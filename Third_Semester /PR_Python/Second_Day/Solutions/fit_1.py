import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy import stats
from uncertainties import ufloat

df = pd.read_csv("exp_decay.csv")
t = df["time_min"].to_numpy()
y = df["counts_per_min"].to_numpy()
N, p = t.size, 3

# --- Modell ---
def rate(t, A, tau, B):
    return A * np.exp(-t / tau) + B

sigma = np.sqrt(y)

p0 = [max(y), t.max()/3, np.median(y[-20:])]

bounds = ([0, 1e-3, 0], [np.inf, np.inf, np.inf])

popt, pcov = curve_fit(rate, t, y, p0=p0, bounds=bounds,
                       sigma=sigma, absolute_sigma=True)

A, tau, B = popt

perr = np.sqrt(np.diag(pcov))
A_err, tau_err, B_err = perr


t12 = ufloat(tau,tau_err) * np.log(2)
print("Halbwertszeit",t12)

t12=t12.n

# --- Residuen & Kennzahlen ---
yhat = rate(t, *popt) # gleich wie: rate(t, A, tau, B)
res = y - yhat
z = res / sigma

chi2 = np.sum(z**2)
chi2_red = chi2 / (N - p)

k2, p_norm = stats.normaltest(z) 
skew = stats.skew(z, bias=False)
ex_kurt = stats.kurtosis(z, fisher=True, bias=False)

print("Fit (gew. LS):")
print(f"A = {A:.2f} ± {perr[0]:.2f}")
print(f"tau = {tau:.2f} ± {perr[1]:.2f} min   ->  t1/2 = {t12:.2f} min")
print(f"B = {B:.2f} ± {perr[2]:.2f}")
print(f"reduziertes chi^2 = {chi2_red:.2f}   (≈1 bei passendem Rauschmodell)")
print(f"Normalitätstest p = {p_norm:.2e}   (klein -> Nicht-Normalität)")
print(f"Schiefe = {skew:.2f},  Überschusskurtosis = {ex_kurt:.2f}")

tt = np.linspace(t.min(), t.max(), 600)

plt.figure()
plt.scatter(t, y, s=15, label="Daten (counts/min)")
plt.plot(tt, rate(tt, *popt), label="Fit", linewidth=2)
plt.xlabel("time [min]"); plt.ylabel("counts per minute")
plt.title("Exponentieller Zerfall: Daten & Fit")
plt.legend(); plt.tight_layout(); plt.show()

plt.figure()
plt.plot(t, res, marker="o", linestyle="none", label="Residuen")
plt.axhline(0, linestyle="--")
plt.xlabel("time [min]"); plt.ylabel("residuals (counts/min)")
plt.title("Residuen vs. Zeit")
plt.legend(); plt.tight_layout(); plt.show()

plt.figure()
plt.hist(z, bins=20, density=True, alpha=0.8, label="standardisierte Residuen")
xx = np.linspace(-5, 5, 400)
plt.plot(xx, stats.norm.pdf(xx), label="N(0,1) PDF")
plt.xlabel("z"); plt.ylabel("density")
plt.title("Verteilung der standardisierten Residuen")
plt.legend(); plt.tight_layout(); plt.show()

plt.figure()
stats.probplot(z, dist="norm", plot=plt.gca())
plt.title("Q–Q-Plot vs. Normal")
plt.tight_layout(); plt.show()

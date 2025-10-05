import numpy as np
import matplotlib.pyplot as plt

times, values = np.genfromtxt("timeseries.dat", delimiter=";").T

plt.rc('font', family='sans-serif', serif='cm', size=14)  # font settings
fig, ax = plt.subplots(figsize=(20, 8))
ax.plot(times, values, ls='-', lw=2, color="k")
ax.plot(times, [np.mean(values)] * len(times), ls="--", lw=2, color="magenta", label=f"Mittelwert: {np.mean(values):.2f}")
n_sigma = 1
ax.fill_between(times, np.mean(values) - n_sigma * np.std(values), np.mean(values) + n_sigma * np.std(values), color="red", alpha=0.3, label=f"Standardabweichung: {np.std(values):.2f}")
n_sigma = 3
ax.fill_between(times, np.mean(values) - n_sigma * np.std(values), np.mean(values) + n_sigma * np.std(values), color="orange", alpha=0.3, label=f"{n_sigma} Standardabweichungen")
ax.set_xlabel("Zeit in Sekunden")
ax.set_ylabel("Messwert in a.u.")
ax.set_title("timeseries.dat")
ax.grid(True)
ax.set_xlim([np.min(times)-(np.max(times)*0.01), np.max(times)*1.01])
ax.set_ylim([np.mean(values)-5*np.std(values), np.mean(values)+5*np.std(values)])
ax.legend()
plt.show()
plt.close()

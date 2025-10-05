import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import UnivariateSpline

df = pd.read_csv("Barometer.csv")

t = df["seconds_elapsed"].to_numpy()
h = df["relativeAltitude"].to_numpy()

vz_raw = np.gradient(h, t)
vmax_raw = np.max(vz_raw)
vmin_raw = np.min(vz_raw)

print(f"[RAW] Max climb rate: {vmax_raw:.2f} m/s")
print(f"[RAW] Max sink rate : {vmin_raw:.2f} m/s")

# --- Spline-Fit ---
N = len(t)
var_h = np.var(h)
s0 = 0.000001 * N * var_h   # wenig glättend;

spline = UnivariateSpline(t, h, s=s0)        # glättender Spline
spline_der = spline.derivative()             # 1. Ableitung

vz_spline = spline_der(t)
vmax_spline = np.max(vz_spline)
vmin_spline = np.min(vz_spline)

print(f"[Spline s={s0:.2e}] Max climb rate: {vmax_spline:.2f} m/s")
print(f"[Spline s={s0:.2e}] Max sink rate : {vmin_spline:.2f} m/s")

s_values = s0 * np.geomspace(0.01, 100, 7)  # 7 Werte um s0 herum
vmax_list, vmin_list = [], []

for s in s_values:
    spl = UnivariateSpline(t, h, s=s)
    vz = spl.derivative()(t)
    vmax_list.append(np.max(vz))
    vmin_list.append(np.min(vz))

# --- Plots ---
plt.figure(figsize=(12, 8))

# (1) Höhe roh vs. Spline
plt.subplot(3, 1, 1)
plt.plot(t, h, label="Altitude (raw)", alpha=0.6)
plt.plot(t, spline(t), label=f"Altitude (spline, s={s0:.1e})", linewidth=2)
plt.ylabel("Altitude [m]")
plt.legend(loc="best")

# (2) Vertikalgeschwindigkeit roh vs. Spline
plt.subplot(3, 1, 2)
plt.plot(t, vz_raw, label="Vertical speed (raw)", alpha=0.5)
plt.plot(t, vz_spline, label="Vertical speed (spline)", linewidth=2)
plt.axhline(0, color="k", ls="--", linewidth=1)
plt.ylabel("Vertical speed [m/s]")
plt.legend(loc="best")

# (3) Einfluss des Glättungsparameters
plt.subplot(3, 1, 3)
plt.semilogx(s_values, vmax_list, "o-", label="max climb")
plt.semilogx(s_values, vmin_list, "o-", label="max sink")
plt.xlabel("Spline smoothing s (log)")
plt.ylabel("Value")
plt.title("Einfluss des Glättungsparameters s")
plt.legend(loc="best")

plt.tight_layout()
plt.show()

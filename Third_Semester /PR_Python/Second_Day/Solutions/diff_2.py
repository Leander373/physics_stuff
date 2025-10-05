import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv("Barometer.csv") # Pandas zum Einlesen der Daten
# Umwandeln in normale Arrays, für Weiterverarbeitung mit Numpy:
t = df["seconds_elapsed"].values
h = df["relativeAltitude"].values

vz = np.gradient(h, t) # Vertikalgeschwindigkeit

vmax = np.max(vz)
vmin = np.min(vz)
print(f"Max climb rate: {vmax:.2f} m/s") # Format-Specifier .2f für 2 Dezimalstellen (https://www.geeksforgeeks.org/python/string-formatting-in-python/)
print(f"Max sink rate: {vmin:.2f} m/s")


def running_avg(x, y, window_size=3): # Standardwert von 3 für window_size
    y_avg = np.convolve(y, np.ones(window_size)/window_size, mode='valid')
    x_new = x[window_size-1:] # entferne erste Einträge, für die es keine Mittelwerte gibt
    return x_new,y_avg

# Die Funktion kann mit
# running_avg(x,y) oder running_avg(x,y,20)
# aufgerufen werden.




plt.figure(figsize=(12, 6))
plt.subplot(2, 1, 1)
plt.plot(t, h, label="Altitude (raw)")
plt.ylabel("Altitude [m]")
plt.legend()

plt.subplot(2, 1, 2)
plt.plot(t, vz, label="Vertical speed (raw)")
t_avg,vz_avg = running_avg(t,vz)
plt.plot(t_avg, vz_avg, label="Vertical speed (avg, window 3)")
t_avg,vz_avg =running_avg(t,vz,window_size=20)
plt.plot(t_avg,vz_avg, label="Vertical speed (avg,window 20)")
plt.axhline(0, color="black", ls="--") # horizontale gestrichelte Linie bei y=0
plt.xlabel("Time [s]")
plt.ylabel("Vertical speed [m/s]")
plt.legend()

plt.tight_layout() # Ränder etwas schmaler, Platz besser ausgenützt
# plt.show() # Plot direkt anzeigen
plt.savefig("plot.pdf") # Plot als PDF abspeichern
plt.savefig("plot.png", dpi=1200) # Plot als Bild mit hoher Auflösung abspeichern
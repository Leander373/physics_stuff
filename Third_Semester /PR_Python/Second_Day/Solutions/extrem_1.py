import numpy as np
from scipy.optimize import minimize_scalar
from scipy.constants import g # importiere Konstante
import matplotlib.pyplot as plt

v0 = 40.0 # m/s

def R(theta):
    return (v0**2 / g) * np.sin(2*theta)
    # numpy sind die Winkel in radiant

res = minimize_scalar(lambda th: -R(th)) #, bounds=(0, np.pi/2))

theta_star = np.rad2deg(res.x) # rad in Grad umzuwandeln
R_star = -res.fun

print(f"Optimaler Winkel θ* = {theta_star:.2f}°")
print(f"Maximale Reichweite R* = {R_star:.2f} m")

angles = np.linspace(0, np.pi/2, 200)
Rvals = R(angles)


plt.plot(angles,Rvals)
plt.axvline(res.x,0,1,color="black")
plt.show()
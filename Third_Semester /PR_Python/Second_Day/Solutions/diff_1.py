import numpy as np
from scipy.optimize import approx_fprime


def f(x): # x als Vektor, da approx_fprime einen numpy-Vektor erwartet
    return np.sin(x[0]) * np.cos(x[1])

# Alternative Definition der Funktion f:
# f = lambda x: np.sin(x[0]) * np.cos(x[1])


x0 = np.array([np.pi / 4, np.pi / 3])
grad_num = approx_fprime(x0, f)

grad_exact = np.array( # setze Werte von x0 direkt ein
    [np.cos(x0[0]) * np.cos(x0[1]), -np.sin(x0[0]) * np.sin(x0[1])]  # df/dx  # df/dy
)

print("Numerischer Gradient:", grad_num)
print("Exakter Gradient:    ", grad_exact)
print("Abweichung:          ", grad_num - grad_exact)

# berechne absolute Abweichung
print("Abweichung abs.", np.abs(grad_num-grad_exact))

# berechne maximale absolute Abweichung
print("Abweichung abs. max.", np.max(np.abs(grad_num-grad_exact)))

import numpy as np
import matplotlib.pyplot as plt

def cd(f, x, h):
    return (f(x + h) - f(x - h)) / (2 * h)

f = np.sin
# def f(x):
#     return np.sin(x)
df = np.cos

x = np.linspace(0, 2 * np.pi, 2001)

hs = np.logspace(-12, -3, 200)
max_err = []
mean_err = []

for h in hs:
    approx = cd(f, x, h)
    err = np.abs(approx - df(x))
    max_err.append(err.max())
    mean_err.append(err.mean())

h_opt = np.finfo(float).eps ** (1 / 3)  # warum hoch 1/3?
# h_opt = np.finfo(float).eps ** (1 / 2)

plt.figure()
plt.loglog(hs, max_err, ".", label="max abs error over x")
plt.loglog(hs, mean_err, ".", label="mean abs error over x", alpha=0.6)
plt.axvline(h_opt, ls="--", color="r", label=f"h* ≈ {h_opt:.2e}")
plt.xlabel("h")
plt.ylabel("error")
plt.title("Central difference error for d/dx sin(x)")
plt.legend()
plt.tight_layout()
plt.show()

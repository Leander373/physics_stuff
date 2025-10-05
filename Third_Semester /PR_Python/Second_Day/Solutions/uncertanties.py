# Nice documentation here:
# * https://pythonhosted.org/uncertainties/index.html
# * https://pythonhosted.org/uncertainties/numpy_guide.html


from uncertainties import ufloat, umath, unumpy

a = ufloat(2, 0.001) # 2 mit Standardabweichung 0.001
b = ufloat(0.75, 0.001)

print(a)
print(b)
print(a/b)

x = umath.cos(a*b)

print(x.n) # eigentlicher ("nominaler") Wert
print(x.s) # Standardabweichung ("standard deviation")


v = unumpy.uarray([1, 2], [0.01, 0.002])

print(v)
print(unumpy.cos(v*x))
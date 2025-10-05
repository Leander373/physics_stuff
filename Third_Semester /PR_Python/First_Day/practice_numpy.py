import numpy as np 

a1 = np.array([20, 55, 6.5])
a2= np.array([27.5, 3, 8])

A1 = np.array([[5, 7, 9], 
               [10, 2, 0],
               [1, 0, 1]])
A2 = np.array([[7.5, 9, 33],
               [0, 4, 5], 
               [2, 0, 6]])

# i
print("i.")
print(a1 + a2)
print()

# ii
print("ii.")
print(a1 @ a2)
print()

# iii
print("iii.")
print(A1 + A2)
print()

#iv
print("iv.")
print(A1 @ A2)
print()

#v
print("v.")
print(A1 @ a1)
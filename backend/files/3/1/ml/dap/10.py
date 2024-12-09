import numpy as np

# Create a 2-D array
a = np.array([[1, 2, 3], [4, 5, 6], [6, 7, 8]])
print("Original array:")
print(a)

# Swapping the rows of the array in reverse order
b = a[::-1, :]
print("\nArray with rows swapped in reverse order:")
print(b)

# Swapping the columns of the array in reverse order
c = a[:, ::-1]
print("\nArray with columns swapped in reverse order:")
print(c)

# Swapping both rows and columns in reverse order
d = a[::-1, ::-1]
print("\nArray with both rows and columns swapped in reverse order:")
print(d)

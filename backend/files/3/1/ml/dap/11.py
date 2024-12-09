import numpy as np

# Create a 2-D array
a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
print("Original Array:")
print(a)

# Computing the mean, median, standard deviation, and variance along the second axis (rows)
mean = np.mean(a, axis=1)
median = np.median(a, axis=1)
std_dev = np.std(a, axis=1)
variance = np.var(a, axis=1)

# Printing the mean, median, standard deviation, and variance along the second axis
print("\nMean along the second axis (rows):", mean)
print("Median along the second axis (rows):", median)
print("Standard deviation along the second axis (rows):", std_dev)
print("Variance along the second axis (rows):", variance)

# Computing the mean, median, standard deviation, and variance along the first axis (columns)
mean = np.mean(a, axis=0)
median = np.median(a, axis=0)
std_dev = np.std(a, axis=0)
variance = np.var(a, axis=0)

# Printing the mean, median, standard deviation, and variance along the first axis
print("\nMean along the first axis (columns):", mean)
print("Median along the first axis (columns):", median)
print("Standard deviation along the first axis (columns):", std_dev)
print("Variance along the first axis (columns):", variance)

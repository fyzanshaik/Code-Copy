import numpy as np

# Creating two arrays: Student IDs and their respective Heights
student_ID = np.array([101, 102, 103, 104, 105])
heights = np.array([5.5, 6.1, 5.8, 5.7, 6.0])

# Print the arrays
print("Student IDs:", student_ID)
print("Student's Heights:", heights)

# Combine the data into a 2-D array (Student ID and Heights together)
data = np.column_stack((student_ID, heights))
print("\nCombined Data:\n", data)

# Sort the data by Heights (Column Index 1)
sorted_indices = np.argsort(data[:, 1])
sorted_data = data[sorted_indices]

# Extract sorted Student IDs and Heights
sorted_student_ID = sorted_data[:, 0]
sorted_heights = sorted_data[:, 1]

# Print the results
print("\nSorted Indices (Based on Height):", sorted_indices)
print("Sorted Student IDs:", sorted_student_ID)
print("Sorted Student's Heights:", sorted_heights)

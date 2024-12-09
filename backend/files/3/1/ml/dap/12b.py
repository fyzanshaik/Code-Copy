import numpy as np

# Creating two arrays: Employee IDs and their respective Wages
employee_ID = np.array([201, 202, 203, 204, 205])
wages = np.array([50000, 60000, 55000, 52000, 58000])

# Printing the arrays
print("Employee IDs:", employee_ID)
print("Employee Wages:", wages)

# Combine the data into a 2-D array (Employee ID and Wages together)
data = np.column_stack((employee_ID, wages))
print("\nCombined Data:\n", data)

# Sort the data by Wages (Column Index 1)
sorted_indices = np.argsort(data[:, 1])
sorted_data = data[sorted_indices]

# Extract sorted Employee IDs and Wages
sorted_employee_ID = sorted_data[:, 0]
sorted_wages = sorted_data[:, 1]

# Print the results
print("\nSorted Indices (Based on Wages):", sorted_indices)
print("Sorted Employee IDs:", sorted_employee_ID)
print("Sorted Employee Wages:", sorted_wages)

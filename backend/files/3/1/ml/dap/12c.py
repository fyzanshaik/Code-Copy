import numpy as np

# Creating two arrays: Book names and their respective Prices
book_names = np.array(["Book A", "Book B", "Book C", "Book D", "Book E"])
prices = np.array([250, 150, 300, 200, 180])

# Printing the arrays
print("Book Names:", book_names)
print("Book Prices:", prices)

# Combine the data into a 2-D array (Book names and Prices together)
data = np.column_stack((book_names, prices))
print("\nCombined Data:\n", data)

# Sort the data by Prices (Column Index 1)
sorted_indices = np.argsort(data[:, 1])
sorted_data = data[sorted_indices]

# Extract sorted Book Names and Prices
sorted_book_names = sorted_data[:, 0]
sorted_prices = sorted_data[:, 1]

# Print the results
print("\nSorted Indices (Based on Prices):", sorted_indices)
print("Sorted Book Names:", sorted_book_names)
print("Sorted Book Prices:", sorted_prices)

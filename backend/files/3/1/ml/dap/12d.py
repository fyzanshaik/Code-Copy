import numpy as np

# Creating two arrays: Product names and their respective Prices
product_names = np.array(["Product A", "Product B", "Product C", "Product D"])
prices = np.array([250, 150, 300, 200])

# Printing the arrays containing Product names and their respective Prices
print("Product Names:", product_names)
print("Product Prices:", prices)

# Combine the data into a 2-D array (Product names and Prices together)
data = np.column_stack((product_names, prices))
print("\nCombined Data:\n", data)

# Sort the data by Prices (Column Index 1)
sorted_indices = np.argsort(data[:, 1].astype(float))  # Convert prices to float if needed
sorted_data = data[sorted_indices]

# Extract sorted Product Names and Prices
sorted_product_names = sorted_data[:, 0]
sorted_prices = sorted_data[:, 1]

# Print the results
print("\nSorted Indices (Based on Prices):", sorted_indices)
print("Sorted Product Names:", sorted_product_names)
print("Sorted Product Prices:", sorted_prices)

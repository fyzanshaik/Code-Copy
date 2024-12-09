import numpy as np
import matplotlib.pyplot as plt

# Create a random number generator
rand = np.random.RandomState(42)

# Define the mean vector and covariance matrix
mean = [0, 0]
cov = [[1, 2], [2, 5]]

# Generate 100 samples from a multivariate normal distribution
X = rand.multivariate_normal(mean, cov, 100)

# Print the shape of the generated array
print(X.shape)

# Randomly select 20 unique indices without repetition
indices = np.random.choice(X.shape[0], 20, replace=False)
print(indices)

# Select rows from X corresponding to the chosen indices
selection = X[indices]

# Print the shape of the selected rows
print(selection.shape)

# Scatter plot for all data points
plt.scatter(X[:, 0], X[:, 1], alpha=0.5)

# Scatter plot for selected points, highlighted in red
plt.scatter(selection[:, 0], selection[:, 1], facecolor='r', s=150)

# Display the plot
plt.show()

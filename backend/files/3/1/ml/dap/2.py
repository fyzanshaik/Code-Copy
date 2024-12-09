import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv(r"/content/Seattle2014.csv")
print(data.shape)
print(data.head())
rainfall = data["PRCP"].values
print(rainfall)
inches = rainfall / 254
print(inches.shape)

plt.hist(inches, 40)
plt.show()

print("Number of days without rain: ", np.sum(inches == 0))
print("Number of days with rain: ", np.sum(inches != 0))
print("Number of days with rain more than 0.5 inches: ", np.sum(inches > 0.5))
print("Number of days with rain < 0.2 inches: ", np.sum((inches > 0) & (inches < 0.2)))

rainy = (inches > 0)
days = np.arange(365)
summer = (days > 172) & (days < 262)
print("Median precip on rainy days in 2014 (inches):", np.median(inches[rainy]))
print("Median precip on summer days in 2014 (inches):", np.median(inches[summer]))
print("Maximum precip on summer days in 2014 (inches):", np.max(inches[summer]))
print("Median precip on non-summer rainy days (inches):", np.median(inches[rainy & ~summer]))

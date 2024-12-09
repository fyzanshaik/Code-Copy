import numpy as np
import pandas as pd
import seaborn as sns

# Load the Titanic dataset
titanic = sns.load_dataset('titanic')

# Display the average survival rate for each combination of passenger 'sex' and 'class'
# Group by 'sex' and 'class' and calculate the mean of 'survived', then unstack the result
print(titanic.groupby(['sex', 'class'])['survived'].aggregate('mean').unstack())

# Use a pivot table to calculate the average survival rate for each combination of 'sex' and 'class'
print(titanic.pivot_table(values='survived', index='sex', columns='class'))

# Create a multi-level pivot table with age groups (0, 18, 80) and calculate the average survival rate
age1 = pd.cut(titanic['age'], [0, 18, 80])
print(titanic.pivot_table(values='survived', index=['sex', age1], columns='class'))

# Split the 'fare' column into two categories (low and high) using quantile-based binning
fare1 = pd.qcut(titanic['fare'], 2)

# Create a pivot table showing average survival rate, grouped by 'sex', age category, 'fare' category, and 'class'
print(titanic.pivot_table('survived', ['sex', age1], [fare1, 'class']))

# Create a pivot table to show total survivors and average fare, grouped by 'sex' and 'class'
print(titanic.pivot_table(index='sex', columns='class', aggfunc={'survived': sum, 'fare': 'mean'}))

# Create a pivot table with margins, displaying overall averages for rows and columns
print(titanic.pivot_table('survived', index='sex', columns='class', margins=True))

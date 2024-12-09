import pandas as pd

# Create the first DataFrame
df1 = pd.DataFrame(
    {'Name': ['Peter', 'Paul', 'Mary'], 'Food': ['Fish', 'Beans', 'Bread']}
).set_index("Name")

# Create the second DataFrame
df2 = pd.DataFrame(
    {'Name': ['Mary', 'Joseph'], 'Drink': ['Wine', 'Beer']}
).set_index("Name")

# Print both DataFrames
print(df1, end="\n\n")
print(df2, end="\n\n")

# Join df1 with df2 using "left" join (df1 as the main DataFrame)
print(df1.join(df2, how="left"), end="\n\n")

# Join df1 with df2 using "right" join (df2 as the main DataFrame)
print(df1.join(df2, how="right"), end="\n\n")

# Join df1 with df2 using "inner" join (only common elements)
print(df1.join(df2, how="inner"), end="\n\n")

# Create two additional DataFrames for testing suffix handling
df3 = pd.DataFrame(
    {'Name': ['Bob', 'Jake', 'Lisa', 'Sue'], 'Rank': [1, 2, 3, 4]}
).set_index("Name")

df4 = pd.DataFrame(
    {'Name': ['Bob', 'Jake', 'Lisa', 'Sue'], 'Rank': [3, 1, 4, 2]}
).set_index("Name")

# Print the new DataFrames
print(df3, end="\n\n")
print(df4, end="\n\n")

# Join df3 with df4, adding suffixes to handle column name conflicts
print(df3.join(df4, lsuffix="_L", rsuffix="_R"))

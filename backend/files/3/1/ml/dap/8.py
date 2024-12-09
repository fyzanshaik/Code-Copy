import pandas as pd

# Create a Series DataFrame with names
monte = pd.Series(['Graham Chapman', 'John Cleese', 'Terry Gilliam', 'Eric Idle', 'Terry Jones', 'Michael Palin'])
print(monte)

# Lowercase all strings in the Series
print(monte.str.lower())

# Check if any string starts with the letter 'T'
print(monte.str.startswith('T'))

# Split the Series into two columns
print(monte.str.split())

# Extract the first name (first word) from each entry
print(monte.str.extract('([A-Za-z]+)', expand=False))

# Find names that start and end with a consonant using regex
print(monte.str.findall(r'^[^AEIOU].*[^aeiou]$'))

# Extract the first 3 characters of each name
print(monte.str[0:3])

# Extract the last name (last word) of each entry
print(monte.str.split().str.get(-1))

# Create a DataFrame with the 'name' and 'info' columns
full_monte = pd.DataFrame({'name': monte, 'info': ['B|C|D', 'B|D', 'A|C', 'B|D', 'B|C', 'B|C|D']})
print(full_monte)

# Split the 'info' column by '|' and create new columns for each unique value
print(full_monte['info'].str.get_dummies('|'))

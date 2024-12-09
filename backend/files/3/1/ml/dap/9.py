import pandas as pd
import numpy as np
import seaborn
import matplotlib.pyplot as plt
from datetime import datetime
from dateutil import parser

# Creating a datetime object representing July 4, 2015
date1 = datetime(year=2015, month=7, day=4)
print(date1)

# Parsing a natural language date string into a datetime object
date2 = parser.parse("4th of July, 2015")
print(date2)

# Creating a numpy datetime64 object for July 4, 2015
date3 = np.array('2015-07-04', dtype=np.datetime64)
print(date3)

# Creating an array of dates starting from 2015-07-04 and increasing by 1 day for each subsequent element
date4 = date3 + np.arange(12)
print(date4)

# Printing a date with day-level precision
print(np.datetime64('2015-07-04'))

# Printing a specific point in time with minute-level precision
print(np.datetime64('2015-07-04 12:00'))

# Creating a datetime object with nanosecond-level precision
print(np.datetime64('2015-07-04 12:59:59.50', 'ns'))

# Using Pandas to convert a human-readable date string into a Timestamp object
date5 = pd.to_datetime("4th of July, 2015")
print(date5)

# Creating a sequence of dates by adding a range of days to a base date
date6 = date5 + pd.to_timedelta(np.arange(12), 'D')
print(date6)

# Creating a Pandas DatetimeIndex for time-based indexing
index = pd.DatetimeIndex(['2014-07-04', '2014-08-04', '2015-07-04', '2015-08-04'])

# Creating a Series with the specified data and a DatetimeIndex
data = pd.Series([0, 1, 2, 3], index=index)
print(data)

# Printing the dates from the given range
print(data['2014-07-04':'2015-07-04'])

# Printing the dates having the specified year
print(data['2015'])

# Converting a list of mixed date formats into Pandas Timestamp objects
dates = pd.to_datetime([datetime(2015, 7, 3), '4th of July, 2015', '2015-Jul-6', '07-07-2015', '20150708'])
print(dates)

# Converting each timestamp into a Period object with daily granularity
print(dates.to_period('D'))

# Computing the time difference between each date in the DatetimeIndex and the first date
print(dates - dates[0])

# Generating a range of dates from July 3, 2015, to July 10, 2015, with daily frequency by default
date_range1 = pd.date_range('2015-07-03', '2015-07-10')
print(date_range1)

# Generating a range of dates starting from July 3, 2015, with a total of 8 periods
date_range2 = pd.date_range('2015-07-03', periods=8)
print(date_range2)

# Generating a range of datetime values starting from July 3, 2015, at 00:00, with a total of 8 periods, spaced at hourly intervals
date_range3 = pd.date_range('2015-07-03', periods=8, freq='H')
print(date_range3)

# Generating a range of Pandas Periods starting from July 2015, with 8 periods, spaced at a monthly frequency
period_range = pd.period_range('2015-07', periods=8, freq='M')
print(period_range)

# Generating a range of time deltas (durations) starting at 0 hours, with 10 periods, spaced at hourly intervals
timedelta_range = pd.timedelta_range(0, periods=10, freq='H')
print(timedelta_range)

# Generating a range of time deltas with a frequency of 2 hours and 30 minutes
timedelta_range2 = pd.timedelta_range(0, periods=9, freq="2H30T")
print(timedelta_range2)

# Loading the Fremont Bridge data
data = pd.read_csv(r"/content/fremont-bridge.csv", index_col='Date', parse_dates=['Date'])
print(data.info())
print(data.head())

# Creating a new 'Total' column by summing 'West' and 'East' columns
data["Total"] = data['West'] + data['East']
print(data.head())

# Dropping missing values
data = data.dropna()
print(data.info())

# Getting a statistical summary of the data
print(data.describe())

# Plotting the hourly bicycle count
seaborn.set()
data.plot(figsize=(20, 6))
plt.grid()
plt.legend(loc='best')
plt.ylabel('Hourly Bicycle Count')
plt.show()

# Resampling to weekly frequency and summing the values
weekly = data.resample("W").sum()
weekly.plot(style=[':', '--', '-'], figsize=(20, 5))
plt.ylabel('Weekly bicycle count')
plt.show()

# Resampling to yearly frequency and summing the values
yearly = data.resample("Y").sum()
yearly.plot(style=[':', '--', '-'], figsize=(20, 5))
plt.ylabel('Yearly bicycle count')
plt.show()

# Resampling to daily frequency and summing the values, then applying a rolling mean
daily = data.resample('D').sum()
daily.rolling(30, center=True).sum().plot(style=[':', '--', '-'], figsize=(20, 5))
plt.ylabel('Mean Hourly Count')
plt.show()

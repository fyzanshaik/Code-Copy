import numpy as np
import pandas as pd

tennis = pd.read_csv('Tennisdataset.csv')
print(tennis)

ct_outlook = pd.crosstab(tennis['outlook'], tennis['play'], margins=True)
print("\nOutlook vs Play:\n", ct_outlook)

ct_temp = pd.crosstab(tennis['temp'], tennis['play'], margins=True)
print("\nTemp vs Play:\n", ct_temp)

ct_humidity = pd.crosstab(tennis['humidity'], tennis['play'], margins=True)
print("\nHumidity vs Play:\n", ct_humidity)

ct_windy = pd.crosstab(tennis['windy'], tennis['play'], margins=True)
print("\nWindy vs Play:\n", ct_windy)

ct_play = pd.crosstab(index=tennis['play'], columns="count", margins=True)
print("\nPlay counts:\n", ct_play)

print("\nGiven Conditions: (Outlook=Sunny, Temp=Hot, Humidity=High, Windy=True)")

a = ct_play.iloc[1,0] / ct_play.iloc[2,0]
b = ct_outlook.loc['sunny','yes'] / ct_outlook.loc['All','yes']
c = ct_temp.loc['hot','yes'] / ct_temp.loc['All','yes']
d = ct_humidity.loc['high','yes'] / ct_humidity.loc['All','yes']
e = ct_windy.loc[True,'yes'] / ct_windy.loc['All','yes']

p_yes = a * b * c * d * e
print('For given conditions, the probability of Tennis is Played: %.3f' % p_yes)

a = ct_play.iloc[0,0] / ct_play.iloc[2,0]
b = ct_outlook.loc['sunny','no'] / ct_outlook.loc['All','no']
c = ct_temp.loc['hot','no'] / ct_temp.loc['All','no']
d = ct_humidity.loc['high','no'] / ct_humidity.loc['All','no']
e = ct_windy.loc[True,'no'] / ct_windy.loc['All','no']

p_no = a * b * c * d * e
print('For given conditions, the probability of Tennis is Not Played: %.3f' % p_no)

if p_yes > p_no:
    print('For given Conditions: Tennis match is Played')
else:
    print('For given Conditions: Tennis match is Not Played')

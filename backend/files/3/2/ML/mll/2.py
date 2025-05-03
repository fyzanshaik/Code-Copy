import numpy as np
import pandas as pd

data = pd.read_csv('Goeswalk.csv')

concepts = np.array(data.iloc[:, :-1])
target = np.array(data.iloc[:, -1])

def train(concepts, target):
    specific_h = concepts[0].copy()
    general_h = [["?" for _ in range(len(specific_h))] for _ in range(len(specific_h))]

    for i, val in enumerate(concepts):
        if target[i].lower() == "yes":
            for x in range(len(specific_h)):
                if val[x] != specific_h[x]:
                    specific_h[x] = '?'
                    general_h[x][x] = '?'
        elif target[i].lower() == "no":
            for x in range(len(specific_h)):
                if val[x] != specific_h[x]:
                    general_h[x][x] = specific_h[x]
                else:
                    general_h[x][x] = '?'

    indices = [i for i, val in enumerate(general_h) if val == ['?'] * len(specific_h)]
    for i in sorted(indices, reverse=True):
        general_h.pop(i)

    return specific_h, general_h

s_final, g_final = train(concepts, target)

print("Final Specific_h:", s_final)
print("Final General_h:", g_final)

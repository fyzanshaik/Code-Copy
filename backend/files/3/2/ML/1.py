import numpy as np
import pandas as pd

dfsport = pd.read_csv("Enjoysport.csv")

concepts = np.array(dfsport)[:, :-1]
target = np.array(dfsport)[:, -1]

def train(concepts, target):
    for i, val in enumerate(target):
        if val == "Yes":
            specific_hypothesis = concepts[i].copy()
            break

    for i, val in enumerate(concepts):
        if target[i] == "Yes":
            for x in range(len(specific_hypothesis)):
                if val[x] != specific_hypothesis[x]:
                    specific_hypothesis[x] = '?'
    return specific_hypothesis

print("The Final Hypothesis is:", train(concepts, target))

import numpy as np
import pandas as pd

eps = np.finfo(float).eps

data = pd.read_csv("ID3.csv")

def find_entropy(df):
    target = df.keys()[-1]
    entropy = 0
    values = df[target].unique()
    for value in values:
        fraction = df[target].value_counts()[value] / len(df[target])
        entropy += -fraction * np.log2(fraction)
    return entropy

def find_entropy_attribute(df, attribute):
    target = df.keys()[-1]
    target_variables = df[target].unique()
    variables = df[attribute].unique()
    entropy2 = 0
    for variable in variables:
        entropy = 0
        for target_variable in target_variables:
            num = len(df[attribute][(df[attribute] == variable) & (df[target] == target_variable)])
            den = len(df[attribute][df[attribute] == variable])
            fraction = num / (den + eps)
            entropy += -fraction * np.log2(fraction + eps)
        fraction2 = den / len(df)
        entropy2 += fraction2 * entropy
    return abs(entropy2)

def bestClassifier(df):
    IG = []
    for key in df.keys()[:-1]:
        IG.append(find_entropy(df) - find_entropy_attribute(df, key))
    return df.keys()[:-1][np.argmax(IG)]

def get_subtable(df, node, value):
    return df[df[node] == value].reset_index(drop=True)

def ID3split(df, tree=None):
    target = df.keys()[-1]
    node = bestClassifier(df)
    attributeValues = np.unique(df[node])
    if tree is None:
        tree = {}
        tree[node] = {}
    for value in attributeValues:
        subtable = get_subtable(df, node, value)
        targetValues, counts = np.unique(subtable[target], return_counts=True)
        if len(counts) == 1:
            tree[node][value] = targetValues[0]
        else:
            tree[node][value] = ID3split(subtable)
    return tree

decisionTree = ID3split(data)
print(decisionTree)

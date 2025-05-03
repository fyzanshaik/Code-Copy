import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

dfsnads = pd.read_csv('Social_Network_Ads.csv')
print(dfsnads.head())

X = dfsnads.iloc[:, 2:4].values  
Y = dfsnads.iloc[:, -1].values   

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=0)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, Y_train)

def predict_new():
    age = int(input("Enter the Age of the User: "))
    salary = int(input("Enter the Salary of the User: "))
    X_new = np.array([[age, salary]])
    X_new_scaled = scaler.transform(X_new)  
    result = knn.predict(X_new_scaled)
    if result == 0:
        print("The User will NOT purchase.")
    else:
        print("The User WILL purchase.")

predict_new()

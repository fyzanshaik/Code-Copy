import numpy as np
import pandas as pd

data_set = pd.read_csv('user_data.csv')
print("Dataset shape:", data_set.shape)
print(data_set)

x = data_set.iloc[:, [2, 3]].values  
y = data_set.iloc[:, 4].values       
print("Features (x):\n", x)
print("Target (y):\n", y)

from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.25, random_state=0)

from sklearn.preprocessing import StandardScaler
st_x = StandardScaler()
x_train = st_x.fit_transform(x_train)
x_test = st_x.transform(x_test)

from sklearn.svm import SVC
classifier = SVC(kernel='linear', random_state=0)
classifier.fit(x_train, y_train)

y_pred = classifier.predict(x_test)

from sklearn.metrics import confusion_matrix
cm = confusion_matrix(y_test, y_pred)
print("Confusion Matrix:\n", cm)

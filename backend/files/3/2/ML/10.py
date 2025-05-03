import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import scipy.cluster.hierarchy as sch
from sklearn.preprocessing import normalize
from sklearn.cluster import AgglomerativeClustering

data = pd.read_csv('Wholesale customers data.csv')
display(data.head())
print(data.shape)

data_scaled = normalize(data.drop(['Channel', 'Region'], axis=1))  
data_scaled = pd.DataFrame(data_scaled, columns=data.columns[2:])  
data_scaled.head()

dendrogram = sch.dendrogram(sch.linkage(data_scaled, method="ward"))
plt.title('Dendrogram')
plt.ylabel('Euclidean distances')
plt.xlabel('Customers')
plt.show()

cluster = AgglomerativeClustering(n_clusters=2, metric='euclidean', linkage='ward')
y_kmeans = cluster.fit_predict(data_scaled)


plt.scatter(data_scaled.iloc[:, 0], data_scaled.iloc[:, 1], c=y_kmeans, cmap='viridis', s=50)
plt.title('Clusters of Customers')
plt.xlabel('Fresh Milk')
plt.ylabel('Grocery')
plt.show()

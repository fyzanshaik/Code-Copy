import numpy as np
import pandas as pd
import warnings
warnings.filterwarnings('ignore')

heart_disease = pd.read_csv("Heartdata.csv")
print(heart_disease.head())
print(f"Dataset shape: {heart_disease.shape}")

# Step-3: Install packages (run only if not already installed)
# Uncomment these if running outside Jupyter
# !pip install pgmpy
# !pip install bayespy

from pgmpy.models import BayesianNetwork  # use 'BayesianNetwork' instead of deprecated 'DiscreteBayesianNetwork'
from pgmpy.estimators import MaximumLikelihoodEstimator

model = BayesianNetwork([
    ('age', 'trestbps'),
    ('age', 'fbs'),
    ('sex', 'trestbps'),
    ('exang', 'trestbps'),
    ('trestbps', 'heartdisease'),
    ('fbs', 'heartdisease'),
    ('heartdisease', 'restecg'),
    ('heartdisease', 'thalach'),
    ('heartdisease', 'chol')
])

model.fit(heart_disease, estimator=MaximumLikelihoodEstimator)

print("\nModel structure:")
print(model.edges())

from pgmpy.inference import VariableElimination

infer = VariableElimination(model)

query_result = infer.query(variables=['heartdisease'], evidence={'trestbps': 150})
print("\nProbability distribution for heartdisease given trestbps=150:")
print(query_result)

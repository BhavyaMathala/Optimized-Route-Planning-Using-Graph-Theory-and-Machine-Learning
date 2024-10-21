import pandas as pd
from sklearn.linear_model import LinearRegression
import numpy as np

# Load traffic data
data = pd.read_csv('traffic_data.csv')

# Prepare data
X = data[['hour', 'day_of_week']].values
y = data['traffic_volume'].values

# Train model
model = LinearRegression()
model.fit(X, y)

def predict_traffic(location):
    # Sample input for prediction (hour and day of week)
    hour = 12  # Example: 12 PM
    day_of_week = 1  # Example: Monday
    prediction = model.predict(np.array([[hour, day_of_week]]))
    return {'location': location, 'predicted_traffic': prediction[0]}

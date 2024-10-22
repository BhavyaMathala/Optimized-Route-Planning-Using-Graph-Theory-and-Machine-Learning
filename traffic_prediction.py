import pandas as pd
from sklearn.linear_model import LinearRegression
import numpy as np

# Load traffic data
data = pd.read_csv('traffic_data.csv')

# Prepare data
X = data[['hour', 'day_of_week']].values
y = data['traffic_volume'].values

# Train model
from sklearn.model_selection import train_test_split
X,X_test,y,y_test=train_test_split(X,y,test_size=0.3,random_state=10)

model = LinearRegression()
model.fit(X, y)

def predict_traffic(location):
    # Sample input for prediction (hour and day of week)
    hour = 12  # Example: 12 PM
    day_of_week = 1  # Example: Monday
    prediction = model.predict(np.array([[hour, day_of_week]]))
    return {'location': location, 'predicted_traffic': prediction[0]}

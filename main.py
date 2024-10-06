import pandas as pd
from sklearn.linear_model import LinearRegression
import mysql.connector

# Connect to MySQL
connection = mysql.connector.connect(
    host='localhost',
    user='your_username',  # Replace with your MySQL username
    password='your_password',  # Replace with your MySQL password
    database='route_planning'
)

# Load data from MySQL into DataFrame
query = "SELECT * FROM routes"
data = pd.read_sql(query, connection)

# Convert categorical variables to dummy/indicator variables
data = pd.get_dummies(data, columns=['traffic', 'weather'], drop_first=True)

# Separate features and target variable
X = data.drop(columns=['id', 'distance'])  # Exclude 'id' and 'distance' columns
y = data['distance']

# Fit the model
model = LinearRegression()
model.fit(X, y)

# Example prediction
# Replace [1, 0, 1, 0] with appropriate values based on your encoding
predicted_distance = model.predict([[1, 0, 1, 0]])  # Example input
print(f"Predicted distance: {predicted_distance[0]}")

# Close the connection
connection.close()

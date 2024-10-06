import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
import mysql.connector

# Connect to MySQL and fetch data
db_connection = mysql.connector.connect(
    host="localhost",
    user="root",
    password="password",
    database="traffic_db"
)

query = "SELECT * FROM traffic_data"
df = pd.read_sql(query, con=db_connection)

# Preprocess data
X = df[['hour_12_1AM', 'hour_1_2AM', 'hour_2_3AM', 'hour_3_4AM', 'hour_4_5AM', 'hour_5_6AM', 'hour_6_7AM', 'hour_7_8AM']]
y = df['hour_8_9AM']

# Split into training and testing datasets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Create and train the model
model = LinearRegression()
model.fit(X_train, y_train)

# Predict future traffic
y_pred = model.predict(X_test)

# Evaluate the model
from sklearn.metrics import mean_squared_error
mse = mean_squared_error(y_test, y_pred)
print(f"Mean Squared Error: {mse}")


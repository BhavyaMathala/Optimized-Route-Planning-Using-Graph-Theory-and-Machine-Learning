import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Load dataset
dataset = pd.read_csv('../Dataset/Traffic_data.csv')

# Preprocess data: select relevant columns and convert to numeric
# Assuming the last column is the target variable (traffic at a certain time)
X = dataset.iloc[:, 7:-1].apply(pd.to_numeric, errors='coerce')  # Features: traffic data at different hours
y = dataset.iloc[:, -1].apply(pd.to_numeric, errors='coerce')  # Target: traffic at a specific time

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)

# Train the model
regressor = LinearRegression()
regressor.fit(X_train, y_train)

# Make predictions
y_pred = regressor.predict(X_test)

# Output results
print("Traffic predictions:", y_pred)
print("Mean Squared Error:", mean_squared_error(y_test, y_pred))


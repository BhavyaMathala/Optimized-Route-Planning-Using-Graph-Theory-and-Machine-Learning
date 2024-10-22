import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

data = pd.read_csv('traffic_data.csv')

# Extract 'day_of_week' from the 'Date' column
data['day_of_week'] = pd.to_datetime(data['Date']).dt.dayofweek

# Reshape the DataFrame to have a 'hour' column and traffic volumes as rows
hourly_columns = ['12:00-1:00 AM', '1:00-2:00AM', '2:00-3:00AM', '3:00-4:00AM', '4:00-5:00AM',
                  '5:00-6:00AM', '6:00-7:00AM', '7:00-8:00AM', '8:00-9:00AM', '9:00-10:00AM',
                  '10:00-11:00AM', '11:00-12:00PM', '12:00-1:00PM', '1:00-2:00PM', '2:00-3:00PM',
                  '3:00-4:00PM', '4:00-5:00PM', '5:00-6:00PM', '6:00-7:00PM', '7:00-8:00PM',
                  '8:00-9:00PM', '9:00-10:00PM', '10:00-11:00PM', '11:00-12:00AM']

# Stack the hourly traffic columns
data_melted = data.melt(id_vars=['Date', 'day_of_week'], 
                        value_vars=hourly_columns, 
                        var_name='hour', 
                        value_name='traffic_volume')

# Create a numeric 'hour' column from the time range string (optional)
data_melted['hour'] = data_melted['hour'].str.extract(r'(\d{1,2}):')[0].astype(int)

# Remove rows with NaN values in 'traffic_volume'
data_melted.dropna(subset=['traffic_volume'], inplace=True)

# Now X will contain 'hour' and 'day_of_week', and y will be 'traffic_volume'
X = data_melted[['hour', 'day_of_week']].values
y = data_melted['traffic_volume'].values

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=10)

# Train a linear regression model
model = LinearRegression()
model.fit(X_train, y_train)

# Define a prediction function
def predict_traffic(location, hour, day_of_week):
    prediction = model.predict(np.array([[hour, day_of_week]]))
    return {'location': location, 'predicted_traffic': prediction[0]}


print(result)


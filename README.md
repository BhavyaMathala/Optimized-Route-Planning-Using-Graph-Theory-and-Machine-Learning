
# Optimized Route Planning Using Graph Theory and Machine Learning

## Project Overview
This project aims to optimize route planning by calculating the shortest paths between cities using graph theory (Dijkstra’s algorithm) and predicting travel times using a machine learning model. The project combines C++ for graph-based pathfinding and Python for machine learning predictions, with MySQL used to store city, route, and traffic data.

## Features
- **Graph Theory**: Use Dijkstra’s algorithm to find the shortest paths between cities.
- **Machine Learning**: Predict travel times based on traffic, weather, and other factors.
- **MySQL Integration**: Store and query city and route data efficiently.


Technologies Used

Languages: C++, Python

Database: MySQL

Libraries:

  1.Python: sklearn, pandas, joblib, requests
  
Tools:

  1.MySQL for data storage
  
  2.  C++ compiler (e.g., g++) for graph algorithms
  
   3. Python 3.6+ for machine learning


Prerequisites

   1. C++ compiler (e.g., g++)

  2.Python 3.6+
  
  3.  MySQL Server
  
  4.Required Python libraries: Install via pip

            "pip install pandas scikit-learn joblib requests"

Database Setup

  1.Install MySQL and set up a new database.
    
  2.Run the SQL script provided in the SQL_Scripts/ folder to create the necessary tables for cities, routes, traffic, and weather data.

        "mysql -u your_username -p route_planning < SQL_Scripts/database_setup.sql"

  3.Populate the tables with your own data or use the sample dataset.

C++ Pathfinding (Dijkstra's Algorithm)

  1.Navigate to the C++_Pathfinding/ directory.
  
  2.Compile the pathfinding.cpp file using g++ or another C++ compiler:

          "g++ pathfinding.cpp -o pathfinding"
   3.Run the executable:

            "./pathfinding"
  4.The program will compute the shortest paths between cities based on predefined edges.

Python Machine Learning Prediction

  1.Navigate to the Python_ML/ directory.
  
  2.Ensure you have the required Python libraries installed (pandas, sklearn, joblib, requests).
  
  3.Train and run the machine learning model by running the ml_prediction.py script:

          "python ml_prediction.py"
          
  4.The script will output predicted travel times based on traffic and weather data from the dataset.


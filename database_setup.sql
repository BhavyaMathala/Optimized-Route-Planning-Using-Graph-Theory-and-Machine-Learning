-- Create the routes table
CREATE TABLE IF NOT EXISTS routes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    city1 VARCHAR(255),
    city2 VARCHAR(255),
    distance INT,
    traffic VARCHAR(50),
    weather VARCHAR(50)
);

-- Load data into the routes table
LOAD DATA INFILE '/path/to/your/data/route_data.csv'
INTO TABLE routes
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n'
IGNORE 1 ROWS
(city1, city2, distance, traffic, weather);

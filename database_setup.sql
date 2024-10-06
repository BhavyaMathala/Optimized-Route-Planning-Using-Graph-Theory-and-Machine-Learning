CREATE TABLE traffic_data (
    id INT,
    segment_id INT,
    roadway_name VARCHAR(100),
    from_location VARCHAR(100),
    to_location VARCHAR(100),
    direction VARCHAR(10),
    date DATE,
    hour_12_1AM INT,
    hour_1_2AM INT,
    hour_2_3AM INT,
    hour_3_4AM INT,
    hour_4_5AM INT,
    hour_5_6AM INT,
    hour_6_7AM INT,
    hour_7_8AM INT,
    hour_8_9AM INT,
    hour_9_10AM INT,
    hour_10_11AM INT,
    hour_11_12PM INT,
    hour_12_1PM INT,
    hour_1_2PM INT,
    hour_2_3PM INT,
    hour_3_4PM INT,
    hour_4_5PM INT,
    hour_5_6PM INT,
    hour_6_7PM INT,
    hour_7_8PM INT,
    hour_8_9PM INT,
    hour_9_10PM INT,
    hour_10_11PM INT,
    hour_11_12AM INT
);

LOAD DATA INFILE 'Traffic_data.csv'
INTO TABLE traffic_data
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n'
IGNORE 1 LINES;




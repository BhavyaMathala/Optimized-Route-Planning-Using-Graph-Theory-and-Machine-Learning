CREATE TABLE IF NOT EXISTS routes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    city1 VARCHAR(255) NOT NULL,
    city2 VARCHAR(255) NOT NULL,
    distance INT NOT NULL,
    traffic ENUM('heavy', 'moderate', 'light') NOT NULL,
    weather ENUM('sunny', 'rainy', 'cloudy') NOT NULL
);

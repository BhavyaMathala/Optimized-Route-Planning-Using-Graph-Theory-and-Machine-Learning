#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>
#include <string>

using namespace std;

// Function to read traffic data from CSV
vector<vector<string>> loadTrafficData(const string& filename) {
    vector<vector<string>> trafficData;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(value);
        }
        trafficData.push_back(row);
    }
    return trafficData;
}

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<string>>& trafficData, int start) {
    int n = trafficData.size();
    vector<int> dist(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (minIndex == -1 || dist[j] < dist[minIndex])) {
                minIndex = j;
            }
        }

        visited[minIndex] = true;

        for (int j = 0; j < n; j++) {
            // Assuming the traffic data can provide the weights for edges
            int weight = stoi(trafficData[minIndex][j + 7]); // Adjust index based on dataset
            if (weight > 0 && dist[minIndex] != numeric_limits<int>::max() && dist[minIndex] + weight < dist[j]) {
                dist[j] = dist[minIndex] + weight;
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < n; i++) {
        cout << "Distance from " << trafficData[start][0] << " to " << trafficData[i][0] << ": " << dist[i] << endl;
    }
}

int main() {
    vector<vector<string>> trafficData = loadTrafficData("../Dataset/Traffic_Data.csv");
    dijkstra(trafficData, 0); // Assuming starting node is the first entry
    return 0;
}


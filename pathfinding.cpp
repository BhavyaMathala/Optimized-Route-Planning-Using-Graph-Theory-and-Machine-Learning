#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

class Graph {
public:
    unordered_map<string, vector<pair<string, int>>> adj; // adjacency list

    void addEdge(const string& u, const string& v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); // for undirected graph
    }

    void dijkstra(const string& start) {
        unordered_map<string, int> dist;
        for (const auto& pair : adj) {
            dist[pair.first] = numeric_limits<int>::max();
        }
        dist[start] = 0;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            string u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adj[u]) {
                string v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Print distances
        for (const auto& pair : dist) {
            cout << "Distance from " << start << " to " << pair.first << " is " << pair.second << endl;
        }
    }
};



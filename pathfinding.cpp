#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <mysql/mysql.h>

using namespace std;

struct Edge {
    int to, weight;
};

// Graph stored as an adjacency list
class Graph {
public:
    map<int, vector<Edge>> adjList;
    
    void addEdge(int from, int to, int weight) {
        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight}); // Assuming it's undirected
    }
    
    vector<int> dijkstra(int source, int n) {
        vector<int> dist(n, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};

int getTrafficWeight(string from, string to, int hour) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    int traffic = INT_MAX;
    
    conn = mysql_init(NULL);
    if (conn == NULL) {
        cout << "mysql_init() failed" << endl;
        return traffic;
    }
    
    if (mysql_real_connect(conn, "localhost", "root", "password", "traffic_db", 0, NULL, 0) == NULL) {
        cout << "mysql_real_connect() failed" << endl;
        mysql_close(conn);
        return traffic;
    }
    
    string query = "SELECT `hour_" + to_string(hour) + "` FROM traffic_data WHERE from_location = '" + from + "' AND to_location = '" + to + "'";
    
    if (mysql_query(conn, query.c_str())) {
        cout << "SELECT failed: " << mysql_error(conn) << endl;
        mysql_close(conn);
        return traffic;
    }
    
    res = mysql_store_result(conn);
    if (res == NULL) {
        cout << "mysql_store_result() failed: " << mysql_error(conn) << endl;
    } else {
        row = mysql_fetch_row(res);
        if (row != NULL) {
            traffic = stoi(row[0]);
        }
    }
    
    mysql_free_result(res);
    mysql_close(conn);
    
    return traffic;
}


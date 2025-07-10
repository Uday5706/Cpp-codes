#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // Infinity value

void floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    // Main logic
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool hasNegativeCycle = false;
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle." << endl;
    } else {
        // Print the shortest distance matrix
        cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    // 0 distance to self
    for (int i = 0; i < n; i++)
        graph[i][i] = 0;

    cout << "Enter edges in format (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w; // For undirected graph, add: graph[v][u] = w;
    }

    floydWarshall(n, graph);
    return 0;
}

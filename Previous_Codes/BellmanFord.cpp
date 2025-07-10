#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e9); // 1-based indexing
    dist[src] = 0;

    // Relax all edges n - 1 times
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            return {-1}; // Negative cycle detected
        }
    }

    return dist;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v w):\n";
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> result = bellmanFord(n, m, src, edges);

    if (result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected!\n";
    } else {
        cout << "Shortest distances from source " << src << ":\n";
        for (int i = 1; i <= n; i++) {
            cout << "To " << i << ": ";
            if (result[i] == 1e9) cout << "INF\n";
            else cout << result[i] << "\n";
        }
    }

    return 0;
}

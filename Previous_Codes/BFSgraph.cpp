#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;

class Graph {
public:
    map<int, set<int>> adj; // set ensures sorted neighbors

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed
        adj[u].insert(v);
        if (direction == 0)
            adj[v].insert(u);
    }

    void bfs(int start, map<int, bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    void bfsDisconnected() {
        map<int, bool> visited;
        cout << "BFS Traversal in Sorted Order: ";
        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                bfs(node, visited);
            }
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    Graph g;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // undirected
    }

    g.bfsDisconnected();

    return 0;
}

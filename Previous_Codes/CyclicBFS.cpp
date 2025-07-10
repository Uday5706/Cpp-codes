#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

class Graph {
public:
    map<int, set<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 → undirected
        adj[u].insert(v);
        if (direction == 0)
            adj[v].insert(u);
    }

    bool isCyclicBFS(int start, map<int, bool>& visited) {
        map<int, int> parent;  // To track parent of each node
        queue<int> q;
        q.push(start);
        visited[start] = true;
        parent[start] = -1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                } else if (parent[node] != neighbor) {
                    // If neighbor is visited and not parent, cycle exists
                    return true;
                }
            }
        }

        return false;
    }

    bool hasCycle() {
        map<int, bool> visited;

        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                if (isCyclicBFS(node, visited))
                    return true;
            }
        }

        return false;
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

    if (g.hasCycle()) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle found in the graph." << endl;
    }

    return 0;
}

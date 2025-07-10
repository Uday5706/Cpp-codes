#include <iostream>
#include <map>
#include <set>
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

    void dfsRecursive(int node, map<int, bool>& visited) {
        // Mark the node as visited and print it
        visited[node] = true;
        cout << node << " ";

        // Recurse for all the unvisited neighbors
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }

    void dfsDisconnected() {
        map<int, bool> visited;
        cout << "DFS Traversal in Sorted Order: ";
        // Traverse through all the nodes, considering disconnected components
        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                dfsRecursive(node, visited);
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

    g.dfsDisconnected();

    return 0;
}

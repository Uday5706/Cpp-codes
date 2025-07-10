#include <iostream>
#include <map>
#include <set>
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

    bool isCyclicDFS(int node, int parent, map<int, bool>& visited) {
        visited[node] = true;

        for (auto neighbor : adj[node]){
            if (!visited[neighbor]){
                if (isCyclicDFS(neighbor, node, visited)) {
                    return true;
                }
            }
            else if (neighbor != parent) {
                // Visited and not parent ⇒ cycle found
                return true;
            }
        }
        return false;
    }

    bool hasCycle() {
        map<int, bool> visited;

        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                if (isCyclicDFS(node, -1, visited)) {
                    return true;
                }
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

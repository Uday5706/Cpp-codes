#include <iostream>
#include <map>
#include <set>
using namespace std;

class Graph {
public:
    map<int, set<int>> adj;

    void addEdge(int u, int v) {
        // Directed graph
        adj[u].insert(v);
    }

    bool dfsCycle(int node, map<int, bool>& visited, map<int, bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCycle(neighbor, visited, recStack))
                    return true;
            } else if (recStack[neighbor]) {
                // Back edge found
                return true;
            }
        }

        recStack[node] = false; // remove from recursion stack
        return false;
    }

    bool isCyclic() {
        map<int, bool> visited, recStack;

        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                if (dfsCycle(node, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    Graph g;

    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.isCyclic())
        cout << "Cycle detected in the directed graph." << endl;
    else
        cout << "No cycle in the directed graph." << endl;

    return 0;
}

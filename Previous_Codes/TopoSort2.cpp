#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    map<int, vector<int>> adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge
    }

    void kahnTopologicalSort() {
        map<int, int> inDegree;

        // Initialize in-degrees to 0 for all nodes
        for (auto& u : adj) {
            int node = u.first;
            inDegree[node] = 0; // Set in-degree to 0 initially for each node
        }

        // Compute in-degrees of all nodes
        for (auto& u : adj) {
            int node = u.first;
            for (int v : u.second) {
                inDegree[v]++;
            }
        }

        // Enqueue all nodes with in-degree 0
        queue<int> q;
        for (auto& u : inDegree) {
            int node = u.first;
            if (inDegree[node] == 0) {
                q.push(node);
            }
        }

        vector<int> topoOrder;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Check if topological sort was successful
        if (topoOrder.size() != adj.size()) {
            cout << "Cycle detected. Topological sort not possible.\n";
        } else {
            cout << "Topological Sort (Kahn's Algorithm): ";
            for (int node : topoOrder) {
                cout << node << " ";
            }
            cout << endl;
        }
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
        g.addEdge(u, v);
    }

    g.kahnTopologicalSort();

    return 0;
}

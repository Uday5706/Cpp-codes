// for Directed Acyclic graph only
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

class Graph {
public:
    map<int, set<int>> adj;

    void addEdge(int u, int v) {
        adj[u].insert(v); // Directed edge
    }

    // ---------- Cycle Detection Using DFS ----------
    bool isCyclicDFS(int node, map<int, bool>& visited, map<int, bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (isCyclicDFS(neighbor, visited, recStack))
                    return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

    bool isCyclic() {
        map<int, bool> visited;
        map<int, bool> recStack;

        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                if (isCyclicDFS(node, visited, recStack))
                    return true;
            }
        }
        return false;
    }

    // ---------- Topological Sort Using DFS ----------
    void topoSortDFS(int node, map<int, bool>& visited, stack<int>& topoStack) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                topoSortDFS(neighbor, visited, topoStack);
            }
        }
        topoStack.push(node);
    }

    void topologicalSort() {
        if (isCyclic()) {
            cout << "Graph has a cycle. Topological sort not possible.\n";
            return;
        }

        map<int, bool> visited;
        stack<int> topoStack;

        for (auto& pair : adj) {
            int node = pair.first;
            if (!visited[node]) {
                topoSortDFS(node, visited, topoStack);
            }
        }

        cout << "Topological Sort: ";
        while (!topoStack.empty()) {
            cout << topoStack.top() << " ";
            topoStack.pop();
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
        g.addEdge(u, v); // directed
    }

    g.topologicalSort();

    return 0;
}

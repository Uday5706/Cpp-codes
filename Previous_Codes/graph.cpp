#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

template <typename T>
class graph {
public:
    unordered_map<T, list<T>> adj;
    vector<vector<int>> adjMatrix;
    int size;

    graph(int n) {
        size = n;
        adjMatrix.resize(n, vector<int>(n, 0));
    }

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed

        // adjacency list
        adj[u].push_back(v);

        // adjacency matrix
        adjMatrix[u][v] = 1;

        if (direction == 0) {
            adj[v].push_back(u);
            adjMatrix[v][u] = 1;
        }
    }

    void printAdjList() {
        cout << "\nAdjacency List:\n";
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void printAdjMatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter no. of nodes and edges: ";
    cin >> n >> m;

    graph<int> g(n);

    cout << "Enter Edges (u v):" << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);  // 0 for undirected graph
    }

    g.printAdjList();
    g.printAdjMatrix();

    return 0;
}

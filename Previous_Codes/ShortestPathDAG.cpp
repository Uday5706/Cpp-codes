#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

map<int, vector<pair<int, int>>> adj;  // adj list (node -> (neighbor, weight))

// Function to add an edge to the graph
void addEdge(int u, int v, int weight) {
    adj[u].push_back({v, weight}); // directed edge with weight
}

// Perform topological sort on the graph
void topologicalSort(int node, map<int, bool>& visited, stack<int>& st) {
    visited[node] = true;
    // Traverse through all the neighbors of the node
    for (auto& u : adj[node]) {
        int neighbor = u.first;
        if (!visited[neighbor]) {
            topologicalSort(neighbor, visited, st);
        }
    }
    st.push(node);  // Push the node to stack after visiting all neighbors
}

// Function to find the shortest path in the DAG
void shortestPath(int src) {
    map<int, bool> visited;
    stack<int> st;

    // Perform topological sort on all nodes
    for (auto& u : adj) {
        if (!visited[u.first]) {
            topologicalSort(u.first, visited, st);
        }
    }

    // Initialize distances for all nodes
    map<int, int> dist;
    for (auto& u : adj) {
        dist[u.first] = INT_MAX;  // Set all node distances to infinity
    }
    dist[src] = 0;  // Distance of source node is 0

    // Relax edges in topologically sorted order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {  // Only process if node is reachable
            // Traverse through all neighbors of the current node
            for (auto& u : adj[node]) {
                int neighbor = u.first;
                int weight = u.second;
                // Relax the edge if a shorter path is found
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                }
            }
        }
    }

    // Print shortest distances from the source node
    cout << "Shortest distances from node " << src << ":\n";
    for (auto& d : dist) {
        cout << "To " << d.first << ": ";
        if (d.second == INT_MAX) cout << "INF";
        else cout << d.second;
        cout << endl;
    }
}

int main() {
    // Add edges to the graph (u -> v with weight)
    addEdge(0, 1, 5);
    addEdge(0, 2, 3);
    addEdge(1, 3, 6);
    addEdge(1, 2, 2);
    addEdge(2, 4, 4);
    addEdge(2, 5, 2);
    addEdge(2, 3, 7);
    addEdge(3, 4, -1);
    addEdge(4, 5, -2);

    int src = 1;  // Source node
    shortestPath(src);  // Find shortest path from source node

    return 0;
}

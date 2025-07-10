#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <climits>
using namespace std;

void primMST(map<int, vector<pair<int, int>>>& adj) {
    map<int, bool> inMST;
    map<int, int> key;
    map<int, int> parent;
    map<int, vector<pair<int, int>>> mst;

    // Collect all unique nodes
    set<int> nodes;
    for (auto it : adj) {
        int u = it.first;
        nodes.insert(u);
        for (auto i : it.second) {
            nodes.insert(i.first);
        }
    }

    // Initialize key and parent
    for (int node : nodes) {
        key[node] = INT_MAX;
        parent[node] = -1;
        inMST[node] = false;
    }

    // Start from any node (first in set)
    int startNode = *nodes.begin();
    key[startNode] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto i : adj[u]) {
            int v = i.first;
            int w = i.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    // Build MST adjacency list
    for (int node : nodes) {
        int par = parent[node];
        if (par != -1) {
            int w = key[node];
            mst[node].push_back({par, w});
            mst[par].push_back({node, w});
        }
    }

    // Print MST adjacency list
    for (auto it : mst) {
        int u = it.first;
        cout << u << " -> ";
        for (auto i : it.second) {
            cout << "{" << i.first << "," << i.second << "} ";
        }
        cout << endl;
    }
}

int main() {
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    map<int, vector<pair<int, int>>> adj;
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    primMST(adj);
    return 0;
}

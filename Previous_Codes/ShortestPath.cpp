#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

void bfs(map<int, vector<int>>& adj, int start, map<int, int>& parent) {
    map<int, bool> visited;
    queue<int> q;

    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
}

void printPath(int end, map<int, int>& parent) {
    if (parent.find(end) == parent.end()) {
        cout << "No path found." << endl;
        return;
    }

    vector<int> path;
    for (int node = end; node != -1; node = parent[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    map<int, vector<int>> adj;
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " undirected edges (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter end node: ";
    cin >> end;

    map<int, int> parent;
    bfs(adj, start, parent);

    if (parent.find(end) == parent.end()) {
        cout << "No path from " << start << " to " << end << ".\n";
    } else {
        printPath(end, parent);
    }

    return 0;
}

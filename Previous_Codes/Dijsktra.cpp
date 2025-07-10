#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(int start, map<int, vector<pair<int, int>>>& adjList, map<int, int>& dist) {
    dist[start] = 0;
    set<pair<int, int>> s;
    s.insert({0, start});

    while (!s.empty()) {
        pair<int, int> current = *s.begin();
        s.erase(s.begin());

        int d = current.first;
        int u = current.second;

        // Traverse all neighbors (u -> v with weight w)
        for (auto& neighbor : adjList[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            // Relaxation step
            if (dist.find(v) == dist.end() || dist[v] > dist[u] + w) {
                if (dist.find(v) != dist.end()) {
                    s.erase({dist[v], v});
                }
                dist[v] = dist[u] + w;
                s.insert({dist[v], v});
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    map<int, vector<pair<int, int>>> adjList;

    // Adding edges (u -> v with weight w)
    adjList[0].push_back({1, 5});
    adjList[0].push_back({2, 6});
    adjList[1].push_back({0, 5});
    adjList[1].push_back({2, -3});
    adjList[2].push_back({0, 6});
    adjList[2].push_back({1, -3});

    map<int, int> dist;
    dijkstra(0, adjList, dist); // Start from node 0

    for (auto it : dist) {
        cout << "Distance to node " << it.first << " = " << it.second << endl;
    }

    return 0;
}

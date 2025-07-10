#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void makeSet(map<int, int> &parent, map<int, int> &rank, vector<vector<int>>& edges){
    for (auto edge : edges){
        parent[edge[0]] = edge[0];
        parent[edge[1]] = edge[1];
        rank[edge[0]] = 0;
        rank[edge[1]] = 0;
    }
}

int findParent(map<int, int> &parent, int node){
    if (parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, map<int, int> &parent, map<int, int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]){
        parent[u] = v;
    } else if (rank[v] < rank[u]){
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    map<int, int> parent, rank;
    makeSet(parent, rank, edges);

    int minWeight = 0;
    vector<vector<int>> mstEdges;

    for (auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (findParent(parent, u) != findParent(parent, v)){
            minWeight += wt;
            unionSet(u, v, parent, rank);
            mstEdges.push_back({u, v, wt});
        }
    }

    cout << "\nMinimum Spanning Tree Edges:\n";
    for (auto edge : mstEdges){
        cout << edge[0] << " -- " << edge[1] << "  weight: " << edge[2] << endl;
    }

    cout << "Total Minimum Weight: " << minWeight << endl;
    return minWeight;
}

int main(){
    int m;
    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter Edges (u v w):\n";

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    minimumSpanningTree(edges);
    return 0;
}

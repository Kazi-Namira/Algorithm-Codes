#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Find the root of a node in the disjoint set (path compression)
int findParent(int u, vector<int>& parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findParent(parent[u], parent);
}

// Merge two sets in the disjoint set
void unionSets(int u, int v, vector<int>& parent)
{
    parent[u] = v;
}

// Kruskal's Algorithm to find the Minimum Spanning Tree (MST)
int kruskal(int n, vector<pair<int, pair<int, int>>>& edges)
{
    sort(edges.begin(), edges.end()); // Sort edges by weight

    vector<int> parent(n);
    for (int i = 0; i < n; ++i)
        parent[i] = i; // Initialize each node as its own parent

    int minCost = 0; // Total cost of MST
    int edgeCount = 0; // Number of edges in the MST
    vector<pair<int, int>> mst; // Store MST edges

    for (auto& edge : edges)
    {
        int u = edge.second.first, v = edge.second.second, cost = edge.first;
        int parentU = findParent(u, parent), parentV = findParent(v, parent);

        if (parentU != parentV) // If adding this edge does not form a cycle
        {
            mst.push_back({u, v});
            minCost += cost;
            unionSets(parentU, parentV, parent);
            edgeCount++;

            if (edgeCount == n - 1) break; // MST complete
        }
    }

    if (edgeCount != n - 1) // Check if MST is possible
    {
        cout << "No spanning tree exists.\n";
        return -1;
    }

    cout << "Minimum Cost Spanning Tree:\n";
    for (auto& edge : mst)
        cout << edge.first << " - " << edge.second << endl;

    return minCost;
}

int main()
{
    int n = 4, m = 5; // Number of vertices and edges

    vector<pair<int, pair<int, int>>> edges =
    {
        {10,{0, 1}},
        {15,{0, 2}},
        {5,{1, 2}},
        {20,{2, 3}},
        {25,{1, 3}}
    };

    int minCost = kruskal(n, edges);

    if (minCost != -1)
        cout << "Total Cost: " << minCost << endl;

    return 0;
}

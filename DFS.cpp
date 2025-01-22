#include <bits/stdc++.h>
using namespace std;

int timeTracker = 0;

// Recursive function to perform DFS starting from vertex u
void DFSVisit(int u, map<int, vector<int>>& adjList, vector<string>& color,
              vector<int>& discoveryTime, vector<int>& finishTime, vector<int>& parent)
{
    color[u] = "GRAY";
    timeTracker++;
    discoveryTime[u] = timeTracker;

    // Explore all adjacent vertices of vertex u
    for (int v : adjList[u])
    {
        if (color[v] == "WHITE")
        {
            parent[v] = u;
            DFSVisit(v, adjList, color, discoveryTime, finishTime, parent);
        }
    }

    color[u] = "BLACK";
    timeTracker++;
    finishTime[u] = timeTracker;
}

// Main DFS function that initializes the search process
void DFS(map<int, vector<int>>& adjList, int vertices)
{
    vector<string> color(vertices, "WHITE");
    vector<int> discoveryTime(vertices, 0);
    vector<int> finishTime(vertices, 0);
    vector<int> parent(vertices, -1);

    // Perform DFS on each unvisited vertex
    for (int u = 0; u < vertices; u++)
    {
        if (color[u] == "WHITE")
        {
            DFSVisit(u, adjList, color, discoveryTime, finishTime, parent);
        }
    }

    // Print the discovery and finish times of all vertices
    cout << "Vertex\tDiscovery\tFinish\n";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "\t" << discoveryTime[i] << "\t\t" << finishTime[i] << "\n";
    }
}

int main()
{
    // Initialize an adjacency list for the graph using map
    map<int, vector<int>> adjList;

    adjList[0] = {1, 3};
    adjList[1] = {2};
    adjList[2] = {3, 4};
    adjList[3] = {};
    adjList[4] = {0};

    int vertices = 5;

    DFS(adjList, vertices);

    return 0;
}

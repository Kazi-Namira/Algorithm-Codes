#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool BellmanFord(int V, int E, vector<int>& u, vector<int>& v, vector<int>& weight, int src, vector<int>& dist)
{
    // Step 1
    dist.assign(V, INT_MAX);
    dist[src] = 0;

    // Step 2
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (dist[u[j]] != INT_MAX && dist[u[j]] + weight[j] < dist[v[j]])
            {
                dist[v[j]] = dist[u[j]] + weight[j];
            }
        }
    }

    // Step 3
    for (int j = 0; j < E; j++)
    {
        if (dist[u[j]] != INT_MAX && dist[u[j]] + weight[j] < dist[v[j]])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> u(E), v(E), weight(E);

    cout << "Enter the edges (u, v, weight): \n";
    for (int i = 0; i < E; i++)
    {
        cin >> u[i] >> v[i] >> weight[i];
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    vector<int> dist(V);

    if (BellmanFord(V, E, u, v, weight, source, dist))
    {
        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                cout << "Vertex " << i << " is unreachable from source.\n";
            }
            else
            {
                cout << "Distance to vertex " << i << " is: " << dist[i] << "\n";
            }
        }
    }
    else
    {
        cout << "Negative-weight cycle detected.\n";
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int source, vector<vector<pii>>& graph, int n)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> distance(n, INT_MAX);

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);

    cout << "Enter the edges (u, v, weight): " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(source, graph, n);

    return 0;
}


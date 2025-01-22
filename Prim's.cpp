#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX

void primMST(int cost[][100], int n)
{
    int near[100];
    int mincost = 0;

    int u, v, min = INF;

    for (int i = 0; i < n; i++) near[i] = INF;

    // Find the edge with the minimum cost to start with
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (cost[i][j] != 0 && cost[i][j] < min)
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    cout << "Edges in the MST:\n";
    cout << u << " - " << v << endl;
    mincost += cost[u][v];
    near[u] = near[v] = 0;

    // Update the near array for all remaining vertices
    for (int i = 0; i < n; i++)
    {
        if (near[i] != 0)
        {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // Repeat the process for the remaining vertices
    for (int i = 1; i < n - 1; i++)
    {
        min = INF;
        int j;

        // Find the vertex with the smallest edge connecting to the MST
        for (int k = 0; k < n; k++)
        {
            if (near[k] != 0 && cost[k][near[k]] < min)
            {
                min = cost[k][near[k]];
                j = k;
            }
        }

        // Output the selected edge and add its weight to the MST cost
        cout << j << " - " << near[j] << endl;
        mincost += cost[j][near[j]];
        near[j] = 0;

        // Update the near array for all remaining vertices
        for (int k = 0; k < n; k++)
        {
            if (near[k] != 0 && cost[k][near[k]] > cost[k][j])
            {
                near[k] = j;
            }
        }
    }

    // Output the total minimum cost of the MST
    cout << "Minimum cost of the MST: " << mincost << endl;
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int cost[100][100];
    cout << "Enter the adjacency matrix (use 0 for no edge):\n";

    // Input the adjacency matrix representing the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0) cost[i][j] = INF; // Replace 0 with INF for no edge
        }
    }

    primMST(cost, n);

    return 0;
}

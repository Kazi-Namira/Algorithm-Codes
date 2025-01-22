#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS traversal on a graph
void BFS(int V, vector<vector<int>>& adj, int s)
{
    // Vector to track visited vertices
    vector<bool> visited(V, false);

    // Vector to store the distance of each vertex from the starting vertex
    vector<int> d(V, -1);

    // Vector to store the parent of each vertex in the BFS tree
    vector<int> pi(V, -1);

    // Queue to hold the vertices to be explored
    queue<int> Q;

    // Mark the starting vertex as visited and set its distance as 0
    visited[s] = true;
    d[s] = 0;

    // Push the starting vertex into the queue
    Q.push(s);

    // Print the starting vertex
    cout << "BFS starting from vertex " << s << ": ";

    // Perform BFS until the queue is empty
    while (!Q.empty())
    {
        // Get the front vertex from the queue
        int u = Q.front();
        Q.pop();

        // Print the current vertex
        cout << u << " ";

        // Explore all the adjacent vertices of the current vertex
        for (int v : adj[u])
        {
            // If the vertex is not visited, mark it as visited
            if (!visited[v])
            {
                visited[v] = true;

                // Set the distance of the adjacent vertex
                d[v] = d[u] + 1;

                // Set the parent of the adjacent vertex
                pi[v] = u;

                // Push the adjacent vertex into the queue for further exploration
                Q.push(v);
            }
        }
    }

    // End of BFS
    cout << endl;
}

int main()
{
    // Number of vertices in the graph
    int V = 5;

    // Adjacency list to represent the graph
    vector<vector<int>> adj(V);

    // Add edges to the graph (undirected edges)
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    // Define the starting vertex for BFS
    int startVertex = 0;

    // Call the BFS function
    BFS(V, adj, startVertex);

    return 0;
}

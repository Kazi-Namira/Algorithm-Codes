#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void floydWarshall(vector<vector<int>>& W)
{
    int n = W.size();

    vector<vector<int>> D = W;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (D[i][k] != INF && D[k][j] != INF)
                {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    cout << "Shortest path matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (D[i][j] == INF)
            {
                cout << "INF" << "\t";
            }
            else
            {
                cout << D[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> W =
    {
        {0, 3, INF, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}
    };

    floydWarshall(W);

    return 0;
}

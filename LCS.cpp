#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
void LCS_LENGTH(const string& X, const string& Y, int m, int n, vector<vector<int>>& c, vector<vector<char>>& b)
{
    // Initialize the LCS table
    for (int i = 0; i <= m; i++)
    {
        c[i][0] = 0; // Base case for the first column
    }
    for (int j = 0; j <= n; j++)
    {
        c[0][j] = 0; // Base case for the first row
    }

    // Fill the LCS table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1; // Characters match
                b[i][j] = 'D'; // Diagonal move
            }
            else if (c[i - 1][j] > c[i][j - 1])
            {
                c[i][j] = c[i - 1][j]; // Move up
                b[i][j] = 'U'; // Up move
            }
            else

            {
                c[i][j] = c[i][j - 1]; // Move left
                b[i][j] = 'L'; // Left move
            }
        }
    }
}

// Function to print the Longest Common Subsequence
void PRINT_LCS(const vector<vector<char>>& b, const string& X, int i, int j)
{
    if (i == 0 || j == 0)
    {
        return; // Base case: reached the top or left of the table
    }
    if (b[i][j] == 'D')   // Diagonal
    {
        PRINT_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1]; // Print character from X
    }
    else if (b[i][j] == 'U')     // Up
    {
        PRINT_LCS(b, X, i - 1, j);
    }
    else     // Left
    {
        PRINT_LCS(b, X, i, j - 1);
    }
}

int main()
{
    string X, Y;
    cout << "Enter first string (X): ";
    cin >> X;
    cout << "Enter second string (Y): ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    // Create tables for storing lengths and directions
    vector<vector<int>> c(m + 1, vector<int>(n + 1));
    vector<vector<char>> b(m + 1, vector<char>(n + 1));

    // Compute the LCS length table and direction table
    LCS_LENGTH(X, Y, m, n, c, b);

    // Print the length of LCS
    cout << "Length of LCS: " << c[m][n] << endl;

    // Print the LCS itself
    cout << "LCS: ";
    PRINT_LCS(b, X, m, n);
    cout << endl;

    return 0;
}

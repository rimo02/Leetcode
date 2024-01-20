#include <iostream>
#include <vector>
using namespace std;
void largestMagicSquare(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> rows(m + 2, vector<int>(n + 2, 0));
    vector<vector<int>> cols(m + 2, vector<int>(n + 2, 0));
    vector<vector<int>> d1(m + 2, vector<int>(n + 2, 0));
    vector<vector<int>> d2(m + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            rows[i][j] += grid[i - 1][j - 1] + rows[i][j - 1];
            cols[i][j] += grid[i - 1][j - 1] + cols[i - 1][j];
            d1[i][j] += grid[i - 1][j - 1] + d1[i - 1][j - 1];
            d2[i][j] += grid[i - 1][j - 1] + d2[i - 1][j + 1];
        }
    }
    cout << "\nrows" << endl;
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << rows[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\ncols" << endl;
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << cols[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nd1" << endl;
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << d1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nd2" << endl;
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            cout << d2[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> grid = {{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}};
    largestMagicSquare(grid);
}
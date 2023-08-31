#include <iostream>
#include <vector>
using namespace std;
int f(int i, int j, vector<int> &arr)
{
    if (i == j)
        return 0;
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + f(i, k, arr) + f(k + 1, j, arr);
        cout << steps << endl;
        if (steps < mini)
            mini = steps;
        // break;
    }
    return mini;
}
//bottom - up
int tabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                    mini = steps;
            }
            dp[i][j] = mini;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    return dp[1][n - 1];
}
int main()
{
    vector<int> arr = {10, 20, 30, 40,50};
    // cout << f(1, arr.size() - 1, arr);
    cout << tabulation(arr);
}
#include <iostream>
#include <vector>
#include <bits./stdc++.h>
using namespace std;
int recursion(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + recursion(s1, s2, m - 1, n - 1);
    }
    else
    {
        return 0 + max(recursion(s1, s2, m - 1, n), recursion(s1, s2, m, n - 1));
    }
}
// Top - Down
int memoization(string s1, string s2, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (dp[m][n] < 0)
    {
        if (s1[m - 1] == s2[n - 1])
        {
            dp[m][n] = 1 + memoization(s1, s2, m - 1, n - 1, dp);
        }
        else
        {
            dp[m][n] = 0 + max(memoization(s1, s2, m - 1, n, dp), memoization(s1, s2, m, n - 1, dp));
        }
    }
    return dp[m][n];
}
// Bottom-up
int tabulation(string s1, string s2, int m, int n, vector<vector<int>> &arr)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
    return dp[m][n];
}
int main()
{
    string S1 = "ababaabaa";
    string S2 = "aababaab";
    // string S1 = "BL";
    // string S2 = "YBY";
    int m = S1.size();
    int n = S2.size();
    cout << S1 << endl
         << S2 << endl;
    // cout << recursion(S1, S2, m, n) << endl;
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, -1));
    // cout << memoization(S1, S2, m, n, arr) << endl;
    cout << tabulation(S1, S2, m, n, arr) << endl;
    // for (int i = 0; i < m + 1; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << arr[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }
}
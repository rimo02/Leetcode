#include <iostream>
#include <vector>
#include <bits./stdc++.h>
using namespace std;
int recursion(string s1, int m, int n)
{
    if (m > n)
        return 0;
    if (m == n)
        return 1;
    if (s1[m] == s1[n])
        return 2 + recursion(s1, m + 1, n - 1);
    else
        return 0 + max(recursion(s1, m + 1, n), recursion(s1, m, n - 1));
}
int memoization(string s1, int m, int n, vector<vector<int>> &dp)
{
    if (m > n)
        return 0;
    if (m == n)
        return 1;
    if (s1[m] == s1[n])
        dp[m][n] = 2 + memoization(s1, m + 1, n - 1, dp);
    else
        dp[m][n] = 0 + max(memoization(s1, m + 1, n, dp), memoization(s1, m, n - 1, dp));
    return dp[m][n];
}
int tabulation(string s1, string s2)
{
    int m = s1.length();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
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
    return dp[m][m];
}
int main()
{
    string s1 = "euazbipz";
    // int n = S1.size();
    // int m = 0;
    // // cout << recursion(S1, m, n - 1) << endl;
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // cout << memoization(S1, m, n, dp);
    string s2;
    reverse_copy(s1.begin(), s1.end(), back_inserter(s2));
    ;
    cout << tabulation(s1, s2);
}
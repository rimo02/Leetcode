#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int recursion(vector<int> &prices, int idx, int n, int buy)
{
    if (idx == n)
        return 0;
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[idx] + recursion(prices, idx + 1, n, 0), 0 + recursion(prices, idx + 1, n, 1));
    }
    else
    {
        profit = max(prices[idx] + recursion(prices, idx + 1, n, 1), 0 + recursion(prices, idx + 1, n, 0));
    }
    return profit;
}
int memoization(vector<int> &prices, int idx, int n, int buy, vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;
    if (dp[idx][buy] != -1)
        return dp[idx][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[idx] + memoization(prices, idx + 1, n, 0, dp), 0 + memoization(prices, idx + 1, n, 1, dp));
    }
    else
    {
        profit = max(prices[idx] + memoization(prices, idx + 1, n, 1, dp), 0 + memoization(prices, idx + 1, n, 0, dp));
    }
    return dp[idx][buy] = profit;
}
int tabulation(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            long profit = 0;
            if (j)
            {
                profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
            }
            else
            {
                profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
            }
            dp[i][j] = profit;
        }
    }
    cout << "\nTabulation Table" << endl;
    for (int i = 0; i < prices.size() + 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    return dp[0][1];
}
int tabulation2(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j >= 0; j--)
        {
            long profit = 0;
            if (j)
            {
                profit = max(-prices[i] + dp[i - 1][1], 0 + dp[i - 1][0]);
            }
            else
            {
                profit = max(prices[i] + dp[i - 1][0], 0 + dp[i - 1][1]);
            }
            dp[i][j] = profit;
        }
    }
    cout << "\nTabulation Table" << endl;
    for (int i = 0; i < prices.size() + 1; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
    return dp[0][1];
}
int main()
{
    vector<int> prices = {2, 1, 4, 5, 2, 9, 7};
    vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    // cout << recursion(prices, 0, prices.size() - 1, 1) << endl;
    cout << "\nProfit from tabulation=" << tabulation(prices) << endl;
    cout << "\nProfit from tabulation=" << tabulation2(prices) << endl;
    // cout << "\nProfit from memoization=" << memoization(prices, 0, prices.size(), 1, dp) << endl;
    // cout << "\nMemoization Table" << endl;
    // for (int i = 0; i < prices.size() + 1; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << dp[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
}
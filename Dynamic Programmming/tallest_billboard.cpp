#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(int idx, int diff, vector<int> &rods)
    {
        if (idx == rods.size())
        {
            if (diff == 0)
                return 0;
            else
                return -1e9;
        }
        int stand1, stand2, reject;
        reject = dfs(idx + 1, diff, rods);
        stand1 = dfs(idx + 1, diff - rods[idx], rods);
        stand2 = rods[idx] + dfs(idx + 1, diff + rods[idx], rods);
        return max({reject, stand1, stand2});
    }
    int memoization(int idx, int diff, vector<int> &rods,
                    vector<vector<int>> &dp)
    {
        if (idx == rods.size())
        {
            if (diff == 0)
                return 0;
            else
                return -1e9;
        }
        if (dp[idx][diff + 5000] != -1)
            return dp[idx][diff + 5000];
        int stand1, stand2, reject;
        reject = memoization(idx + 1, diff, rods, dp);
        stand1 = memoization(idx + 1, diff - rods[idx], rods, dp);
        stand2 = rods[idx] + memoization(idx + 1, diff + rods[idx], rods, dp);
        return dp[idx][diff + 5000] = max({reject, stand1, stand2});
    }
    int tallestBillboard(vector<int> &rods)
    {
        // return dfs(0, 0, rods);
        vector<vector<int>> dp(25, vector<int>(10000, -1));
        return memoization(0, 0, rods, dp);
    }
};
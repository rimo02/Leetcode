#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(int n, int k)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;
        int ans = 1e9;
        for (int i = 1; i <= n; i++)
        {
            int break1 = dfs(i - 1, k - 1);
            int notbreak = dfs(n - i, k);
            ans = min(ans, 1 + max(break1, notbreak));
        }
        return ans;
    }
    int memoization(int k, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;

        if (dp[k][n] != 0)
            return dp[k][n];
        int ans = 1e9;
        for (int i = 1; i <= n; i++)
        {
            int break1 = memoization(k - 1, i - 1, dp);
            int notbreak = memoization(k, n - i, dp);
            int worst = 1 + max(break1, notbreak);
            ans = min(ans, worst);
        }
        return dp[k][n] = ans;
    }
    int memo(int k, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || n == 1)
            return n;
        if (k == 1)
            return n;

        if (dp[k][n] != 0)
            return dp[k][n];
        int ans = 1e9;
        int l = 1, h = n;
        while (l < h)
        {
            int mid = l + (h - l) / 2;
            int break1 = memo(k - 1, mid - 1, dp);
            int notbreak = memo(k, n - mid, dp);
            int worst = 1 + max(break1, notbreak);
            ans = min(ans, worst);
            if (break1 > notbreak)
            {
                h = mid;
            }
            else
                l = mid + 1;
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        int ans = memo(k, n, dp);
        return ans;
    }
};
int main()
{
    Solution S;
    cout << S.superEggDrop(3, 7);
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[101][202];
    int dfs(vector<int> &nums, int i, int M)
    {
        int n = nums.size();
        if (i >= n)
            return 0;
        if (dp[i][M] != -1)
            return dp[i][M];
        int total = 0;
        int res = INT_MIN;
        for (int X = 1; X <= 2 * M; X++)
        {
            if (i + X > n)
                break;
            total += nums[i + X - 1];
            res = max(res, total - dfs(nums, i + X, max(M, X)));
            // ans is the difference betwween total no of stones picked by alice
            // and bob
        }
        return dp[i][M] = res;
    }
    int rec(vector<int> &nums, int i, int M, bool alice)
    {
        int n = nums.size();
        if (i >= n)
            return 0;
        int total = 0;
        int res = alice ? 0 : INT_MAX;
        for (int X = 1; X <= 2 * M; X++)
        {
            if (i + X > n)
                break;
            total += nums[i + X - 1];
            if (alice)
                res = max(res, total + rec(nums, i + X, max(M, X), !alice));
            else
                res = min(res, rec(nums, i + X, max(M, X), !alice));
        }
        return res;
    }
    int tab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int M = 1; M <= n; M++)
            {
                int total = 0;
                int res = INT_MIN;
                for (int X = 1; X <= 2 * M && i + X <= n; X++)
                {
                    total += nums[i + X - 1];
                    res = max(res, total - dp[i + X][max(M, X)]);
                }
                dp[i][M] = res;
            }
        }
        return ((accumulate(nums.begin(), nums.end(), 0) + dp[0][1]) / 2);
    }
    int stoneGameII(vector<int> &piles)
    {

        // _______RECURSION_____________
        // int sum = accumulate(piles.begin(),piles.end(),0);
        // int tot = dfs(piles, 0, 1);
        // // func returns a - b , alice and  bob have a + b, tf (sum + tot)/2
        // return (sum + tot)/2;

        // _______MEMOIZATION____________
        // memset(dp, -1, sizeof(dp));
        // int sum = accumulate(piles.begin(), piles.end(), 0);
        // int tot = dfs(piles, 0, 1);
        // // func returns a - b , alice and  bob have a + b, tf (sum + tot)/2
        // return (sum + tot) / 2;

        // ________TABULATION_____________
        return tab(piles);
    }
};

int main()
{
    vector<int> nums = {2, 7, 9, 4, 4};
    Solution S;
    cout << S.stoneGameII(nums);
}
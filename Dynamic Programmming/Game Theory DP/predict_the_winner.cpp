#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[25][25];
    int dfs(vector<int> &nums, int i, int j, int turn)
    {
        if (i > j)
            return 0;
        int sum = 0;
        if (turn == 0)
        {
            sum = max(nums[i] + dfs(nums, i + 1, j, turn - 1),
                      nums[j] + dfs(nums, i, j - 1, turn - 1));
        }
        else
            sum = min(-nums[i] + dfs(nums, i + 1, j, turn + 1),
                      -nums[j] + dfs(nums, i, j - 1, turn + 1));
        return dp[i][j] = sum;
    }
    int rec(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(nums[i] - rec(nums, i + 1, j, dp),
                              nums[j] - rec(nums, i, j - 1, dp));
    }
    void print(vector<vector<int>> &dp, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    int tab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }
        // DIFFICULT INTUITION
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
                print(dp, n);
            }
        }
        return dp[0][n - 1] >= 0;
    }
    bool predictTheWinner(vector<int> &nums)
    {
        // return dfs(nums, 0, nums.size() - 1, 0) >= 0;
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return rec(nums, 0, nums.size() - 1, dp) >= 0;
        return tab(nums);
    }
};
int main()
{
    vector<int> nums = {1, 7, 2, 8};
    Solution S;
    cout << S.predictTheWinner(nums);
}
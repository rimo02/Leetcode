#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int recursion(vector<int> &nums, int i, int j)
    {
        if (i > j)
            return 0;
        int ans = 1e-9;
        for (int k = i; k <= j; k++)
        {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] + recursion(nums, i, k - 1) + recursion(nums, k + 1, j);
            ans = max(ans, coins);
        }
        return ans;
    }
    int tabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                    continue;
                int ans = 1e-9;
                for (int k = i; k <= j; k++)
                {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    ans = max(ans, coins);
                }
                dp[i][j] = ans;
            }
        }
        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < n + 2; j++)
            {
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }
        return dp[1][n - 1];
    }
    int maxCoins(vector<int> &nums)
    {
        // nums.insert(nums.begin(),1);
        // nums.insert(nums.end(),1);
        // return recursion(nums,1,nums.size()-2);
        return tabulation(nums);
    }
};
int main()
{
    vector<int> nums = {3, 1, 5, 8};
    Solution S;
    cout << S.maxCoins(nums);
}
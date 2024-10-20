#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void another_approach(vector<int> &arr)
    {
        int n = arr.size();
        long long total = 1 << n;
        for (long long i = 0; i < total; i++)
        {
            long long sum = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                {
                    sum += arr[j];
                }
            cout << sum << endl;
        }
    }
    vector<int> DistinctSum(vector<int> nums)
    {

        // Code here
        vector<int> ans;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        for (int j = 0; j <= sum; j++)
        {
            if (dp[n][j] == 1)
                ans.push_back(j);
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3};
    Solution S;
    S.another_approach(arr);
}
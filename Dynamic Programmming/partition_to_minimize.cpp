#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void printdp(vector<vector<bool>> &dp, int n, int target)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                cout << (bool)dp[i][j] << "\t";
            }
            cout << endl;
        }
    }
    int dynamic(vector<vector<bool>> &dp, vector<int> &arr, int n, int target)
    {
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (arr[0] <= target)
            dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                bool notTake = dp[i - 1][j];
                bool take = false;
                if (arr[i] <= j)
                {
                    take = dp[i - 1][j - arr[i]];
                }
                dp[i][j] = take | notTake;
            }
        }
        int mind = INT16_MAX;
        printdp(dp, n, target);
        for (int i = 0; i <= target / 2; i++)
        {
            if (dp[n - 1][i] == true)
            {
                int s1 = i;
                int s2 = target - i;
                mind = min(mind, abs(s2 - s1));
            }
        }
        return mind;
    }
    int minimumDifference(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1, false));
        return dynamic(dp, nums, nums.size(), sum);
    }
};
int main()
{
    vector<int> nums = {3, 9, 7, 3};
    // vector<int> nums = {-36, 36};
    Solution S;
    cout << S.minimumDifference(nums);
}
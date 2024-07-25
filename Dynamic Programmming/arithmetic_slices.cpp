#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        vector<unordered_map<long, long>> dp(nums.size());
        int ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - (long)nums[j];
                if (diff > INT_MAX || diff < INT_MIN)
                    continue;
                dp[i][diff] += 1;
                if (dp[j].count(diff))
                {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                    cout << diff << " " << ans << endl;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {2, 4, 6, 8, 10};
    Solution S;
    cout << S.numberOfArithmeticSlices(arr);
}
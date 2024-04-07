#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        unordered_map<int, int> mp;
        long long ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if(i > 0)
            {
                if (mp.find(nums[i] - k) != mp.end())
                {
                    long long sum = prefix[i - 1] - prefix[mp[nums[i] - k]];
                    ans = max(ans, sum);
                }
                else if (mp.find(nums[i] + k) != mp.end())
                {
                    long long sum = prefix[i - 1] - prefix[mp[nums[i] + k]];
                    ans = max(ans, sum);
                }
            }
            mp[nums[i]] = i;
        }
        return ans == INT_MIN ? 0 : ans;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution S;
    cout << S.maximumSubarraySum(nums, 1);
}
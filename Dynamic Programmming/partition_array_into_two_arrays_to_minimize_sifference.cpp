#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 2;
        vector<vector<int>> left(n + 1), right(n + 1);
        for (int i = 0; i < (1 << n); i++)
        {
            int idx = 0, l_sum = 0, r_sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    idx++;
                    l_sum += nums[j];
                    r_sum += nums[j + n];
                }
                left[idx].push_back(l_sum);
                right[idx].push_back(r_sum);
            }
        }
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i <= n; i++)
        {
            sort(right[i].begin(), right[i].end());
        }
        long long mini = INT_MAX;
        for (int i = 0; i <= n; i++)
        {
            for (auto &a : left[i])
            {
                long long b = sum / 2 - a;
                int idx = n - i; // taking n/2 elements from left and right
                auto &v = right[idx];
                auto lb = lower_bound(v.begin(), v.end(), b); // try to make the sum 
                if (lb != v.end())
                {
                    mini = min(mini, abs(sum - 2 * (a + *lb)));
                }
            }
        }
        return mini;
    }
};
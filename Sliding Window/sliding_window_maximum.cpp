#include <iostream>
#include <utility>
#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (dq.size() > 0 && i - k >= dq.front())
                dq.pop_front();
            while (dq.size() > 0 && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if (i + 1 >= k)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
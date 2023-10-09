#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> previousLess(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> stk; // maintain a monotinically increasing stack
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            if (!stk.empty())
                res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }
    vector<int> nextLess(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> stk; // maintain a monotinically increasing stack
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[stk.top()] > heights[i])
            {
                stk.pop();
            }
            if (!stk.empty())
                res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }
    vector<int> previousGreater(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> stk; // maintain a monotinically decreasing stack
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] <= heights[i])
            {
                stk.pop();
            }
            if (!stk.empty())
                res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }
    vector<int> nextGreater(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> stk; // maintain a monotinically decreasing stack
        vector<int> res(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[stk.top()] < heights[i])
            {
                stk.pop();
            }
            if (!stk.empty())
                res[i] = stk.top();
            stk.push(i);
        }
        return res;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        vector<int> minPrev = previousLess(nums);
        vector<int> minNext = nextLess(nums);
        vector<int> maxPrev = previousGreater(nums);
        vector<int> maxNext = nextGreater(nums);
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long leftMin = i - minPrev[i];
            long long rightMin = minNext[i] - i;
            long long leftMax = i - maxPrev[i];
            long long rightMax = maxNext[i] - i;
            ans += (leftMax * rightMax - leftMin * rightMin) * nums[i];
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {1, 3, 3};
    Solution S;
    cout << S.subArrayRanges(arr);
}
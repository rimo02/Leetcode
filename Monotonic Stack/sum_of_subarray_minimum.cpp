#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    // thought process- how many subarrays ending at i with arr[i] as minimum value
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
    // thought process- how many subarrays starting at i with arr[i] as minimum value
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

    int sumSubarrayMins(vector<int> &arr)
    {
        vector<int> left = previousLess(arr);
        vector<int> right = nextLess(arr);
        int ans = 0;
        int n = arr.size();
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int l = i - left[i];
            int r = right[i] - i;
            long long prod = (l * r) % mod;
            prod = (prod * arr[i]) % mod;
            ans = (ans + prod) % mod;
        }
        return (int)ans;
    }
};
int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    Solution S;
    cout << S.sumSubarrayMins(arr);
}
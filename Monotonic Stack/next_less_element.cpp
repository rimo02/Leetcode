#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// find next less element [3,7,8,4] -> [-1,4,4,-1]
int main()
{
    // vector<int> nums = {3, 7, 8, 4};
    // vector<int> nums = {2, 1, 5, 6, 2, 3};
    vector<int> nums = {3,1,2,4};
    int n = nums.size();
    stack<int> stk; // maintain a monotinically increasing stack
    vector<int> res(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && nums[stk.top()] >= nums[i])
        {
            if (!stk.empty())
                res[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for (auto num : res)
    {
        cout << num << " ";
    }
}
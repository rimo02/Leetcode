#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// find previous less element [3,7,8,4] -> [-1,3,7,3]
int main()
{
    // vector<int> nums = {2, 1, 5, 6, 2, 3};
    vector<int> nums = {3,1,2,4};
    int n = nums.size();
    stack<int> stk; // maintain a monotinically increasing stack
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && nums[stk.top()] > nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
            // res[i] = nums[stk.top()];
            res[i] = stk.top();
        stk.push(i);
    }
    for (auto num : res)
    {
        cout << num << " ";
    }
}
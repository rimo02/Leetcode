#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// find previous less element [3,7,8,4] -> [-1,-1,-1,-1]
int main()
{
    vector<int> nums = {2, 4, 8, 5, 7};
    int n = nums.size();
    stack<int> stk; // maintain a monotinically decreasing stack
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && nums[stk.top()] < nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
            res[i] = nums[stk.top()];
        stk.push(i);
    }
    for (auto num : res)
    {
        cout << num << " ";
    }
}
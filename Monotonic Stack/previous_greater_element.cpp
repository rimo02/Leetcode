#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// find previous greater element [3,7,8,4] -> [-1,-1,-1,-1]
int main()
{
    vector<int> nums = {1,2,3,4};
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
            res[i] = stk.top();
        stk.push(i);
    }
    for (auto num : res)
    {
        cout << num << " ";
    }
}
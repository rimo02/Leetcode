#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// find next greater element [3,7,8,4] -> [7,8,-1,-1]
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    stack<int> stk; // maintain a monotinically decreasing stack
    vector<int> res(n, n);
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && nums[stk.top()] < nums[i])
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
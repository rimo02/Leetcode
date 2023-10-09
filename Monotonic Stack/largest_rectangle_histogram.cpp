#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    // int largestRectangleArea1(vector<int>& heights)
    // {
    //     stack<int> stk;
    //     int area=0;
    //     heights.push_back(0);
    //     for(int i=0;i<heights.size();i++)
    //     {
    //         while(!stk.empty() && heights[stk.top()] > heights[i])
    //         {
    //             int h = heights[stk.top()];
    //             stk.pop();
    //             int w = stk.empty()? -1:stk.top();
    //             area = max(area, h*(i-w-1));
    //         }
    //         stk.push(i);
    //     }
    //     return area;
    // }

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
    int largestRectangleArea2(vector<int> &heights)
    {
        vector<int> left = previousLess(heights);
        vector<int> right = nextLess(heights);
        int ans = INT16_MIN;
        for (int i = 0; i < heights.size(); i++)
        {
            int h = heights[i];
            int w = right[i] - left[i] - 1;
            ans = max(ans, h * w);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    Solution S;
    cout << S.largestRectangleArea2(arr);
}
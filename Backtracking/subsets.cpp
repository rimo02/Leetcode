#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subset;
    vector<int> sub;
    void findsubset(vector<int> &nums, int k)
    {
        subset.push_back(sub);
        for (int i = k; i < nums.size(); i++)   
        {
            sub.push_back(nums[i]);
            for (int el : sub)
                cout << el << " ";
            cout << endl;
            findsubset(nums, k + 1);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        findsubset(nums, 0);
        return subset;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3};
    Solution S;
    vector<vector<int>> ans = S.subsets(nums);
}
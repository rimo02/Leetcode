#include <bits./stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> arr;
        sort(nums.begin(), nums.end());
        // [-4,-1,-1,0,1,2,3]
        // [-6,-4,-3,-3,-2,0,1,2,3,3,4]
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int target = nums[i] + nums[j];
                cout << target << endl;
                if (nums[k] + target == 0)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]}; // Create a vector for the triplet
                    arr.push_back(triplet);
                    j++;
                    k--;
                }
                if (arr[k] > target)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
            i++;
        }
        return arr;
    }
};
int main()
{
    vector<int> num = {-1, -1, 0, 1, 2, 3};
    Solution s;
    vector<vector<int>> out = s.threeSum(num);
    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
}
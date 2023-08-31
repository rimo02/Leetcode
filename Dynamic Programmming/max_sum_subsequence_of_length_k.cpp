#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubsequence(vector<int> &nums, int k, int i)
    {
        if (k == 0 || i < 0)
            return 0;
        int maxsum = 0;
        for (int j = i; j >= 0; j--)
        {
            int sum = maxSubsequence(nums, k - 1, i - 1) + nums[j];
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
    int tabulation(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    }
};
int main()
{
    Solution S;
    vector<int> arr = {7, 2, 3, 4};
    int k = 2;
    cout << S.maxSubsequence(arr, k, arr.size() - 1);
}
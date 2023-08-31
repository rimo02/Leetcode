// find count of subarrays such that their sum equals to target
#include <iostream>
#include <vector>
using namespace std;
int recursion(vector<int> &arr, int idx, int target)
{
    if (target == 0)
    {
        return 1;
    }
    if (idx == 0)
        return arr[0] == target;
    if (arr[idx] > target)
        return recursion(arr, idx - 1, target);
    else
    {
        return recursion(arr, idx - 1, target - arr[idx - 1]) + recursion(arr, idx - 1, target);
    }
}
int tabulation(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            
        }
    }
}
int main()
{
    vector<int> arr = {3, 1, 2, 3, 1};
    int target = 6;
    int idx = arr.size();
    cout << "Output = " << recursion(arr, idx, target);
}
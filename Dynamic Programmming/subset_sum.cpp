#include <iostream>
#include <vector>
using namespace std;
bool sub_sum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (set[n - 1] > sum)
        return sub_sum(set, n - 1, sum);
    return sub_sum(set, n - 1, sum - set[n - 1]) || sub_sum(set, n - 1, sum);
}
// int dynamic_prog(int set[],int n,int target)
// {
//     bool dp[n+1][target+1];
//     // if set is empty
//     // if target is zero
// }

bool memoization(vector<vector<int>> &dp, int arr[], int n, int target)
{
    if (target == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return arr[0] == target;
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    int sum = 10;
    // if (sub_sum(set, n, sum) == false)
    // {
    //     cout << "No solution exist";
    // }
    // else
    // {
    //     cout << "Solution exist";
    vector<vector<int>> dp(n, vector<int>(sum, -1));
    if (memoization(dp, set, n, sum))
    {
        cout << "Solution exist";
    }
    else
    {
        cout << "No solution exist";
    }
}
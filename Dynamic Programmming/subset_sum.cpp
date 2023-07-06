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

bool memoization(vector<vector<int>> &dp, int arr[], int n, int target)
{
    if (target == 0)
        return true;
    if (n == 0)
        return arr[0] == target;
    if (dp[n][target] != -1)
        return dp[n][target];
    bool notTake = memoization(dp, arr, n - 1, target);
    bool take = false;
    if (arr[n] <= target)
    {
        take = memoization(dp, arr, n - 1, target - arr[n]);
    }
    return dp[n][target] = take | notTake;
}

bool dynamic(vector<vector<bool>> &dp, int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = take | notTake;
        }
    }
    return dp[n - 1][target];
}

int main()
{
    int set[] = {3, 1, 2, 5, 4};
    int n = 5;
    int sum = 5;
    // if (sub_sum(set, n, sum) == false)
    // {
    //     cout << "No solution exist";
    // }
    // else
    // {
    //     cout << "Solution exist";
    // }
    // vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    // if (memoization(dp, set, n - 1, sum))
    // {
    //     cout << "Solution exist" << endl;
    // }
    // else
    // {
    //     cout << "No solution exist" << endl;
    // }
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    if (dynamic(dp, set, n, sum))
    {
        cout << "Solution exist" << endl;
    }
    else
    {
        cout << "No solution exist" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}
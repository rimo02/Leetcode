#include <iostream>
#include <vector>
using namespace std;

int recursion(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return arr[0] == sum;
    if (arr[n - 1] > sum)
        return recursion(arr, n - 1, sum);
    return recursion(arr, n - 1, sum - arr[n - 1]) + recursion(arr, n - 1, sum);
}
void printdp(vector<vector<int>> &dp, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            cout << (int)dp[i][j] << "\t";
        }
        cout << endl;
    }
}
void dynamic(vector<vector<int>> &dp, int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= target)
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = take + notTake;
        }
    }
    printdp(dp, n, target);
}
int main()
{
    // int set[] = {3, 1, 2, 5};
    // int set[] = {1, 1, 1};
    int set[] = {1, 2, 1, 2, 1};
    int n = 5;
    int sum = 3;
    // cout << recursion(set, n, sum);
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
    dynamic(dp, set, n, sum);
}
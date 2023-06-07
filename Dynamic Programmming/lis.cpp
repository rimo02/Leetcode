#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Greedy Approach
int greedy(int arr[], int n)
{
    int curr_max = 0, max = 0, curr_ele;
    for (int i = 0; i < n - 1; i++)
    {
        curr_max = 1;
        curr_ele = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > curr_ele)
            {
                curr_max++;
                curr_ele = arr[j];
            }
        }
        if (curr_max > max)
        {
            max = curr_max;
        }
    }
    return max;
}
int recursive(int arr[], int i, int prev, int n)
{
    if (i == n)
    {
        return 0;
    }
    int exclude;
    exclude = 0 + recursive(arr, i + 1, prev, n);
    int include = 0;
    if (arr[i] > prev)
    {
        include = (1 + recursive(arr, i + 1, arr[i], n));
    }
    return max(include, exclude);
}
int recursive2(int arr[], int i, int prev, int n)
{
    if (i == n)
    {
        return 0;
    }
    int exclude;
    exclude = 0 + recursive2(arr, i + 1, prev, n);
    int include = 0;
    if (arr[i] > prev && arr[i] - prev == 1)
    {
        include = (1 + recursive2(arr, i + 1, arr[i], n));
    }
    return max(include, exclude);
}
int dynamicProg(int arr[], int n)
{
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp, dp + n);
}
int dynamic2d(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int notTake = 0 + dp[i + 1][j + 1];
            int take = 0;
            if (j == -1 || arr[i] > arr[j])
            {
                take = 1 + dp[i + 1][i + 1];
            }
            dp[i][j + 1] = max(take, notTake);
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return dp[0][0];
}
int main()
{
    int arr[] = {20, 10, 11, 15, 18, 16, 19, 21, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "Longest Increasing subsequence using greedy approach= " << greedy(arr, n) << endl;
    // cout << "Longest Increasing subsequence using recursion= " << recursive(arr, 0, INT16_MIN, n) << endl;
    // cout << "Longest Increasing subsequence such that diff is 1 using recursion= " << recursive2(arr, 0, arr[0] - 1, n) << endl;
    // cout << "Longest Increasing subsequence using Dynamic programming= " << dynamicProg(arr, n) << endl;
    cout << "Longest Increasing subsequence using 2D array Dynamic programming= " << dynamic2d(arr, n) << endl;
}
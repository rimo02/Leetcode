// There are N cities in a country. George is initially at the airport in city 1 and he wants to
// reach city N. For any city i, there is either a flight to city (i+1) or to (i+3) if it exists.
// You have been given an array A with the costs of flight tickets for N cities. To find the
// cost of a flight ticket between any two cities i and j, you take the absolute difference of
// the costs of those cities in the array A. You can use the formula |a| = |Cost[i] – Cost[j]] to
// calculate the cost of a flight ticket, where la represents the absolute value of a.
// Your task is to find and return the minimum possible cost of flight ticket required to
// reach the city N.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int recursion(vector<int> &arr, int idx, int prev)
{
    if (idx >= arr.size())
        return INT16_MAX;
    if (idx == arr.size() - 1)
        return abs(arr[idx] - prev);
    int take1 = abs(arr[idx] - prev) + recursion(arr, idx + 1, arr[idx]);
    int take2 = abs(arr[idx] - prev) + recursion(arr, idx + 3, arr[idx]);
    return min(take1, take2);
}
void tabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, INT16_MAX);
    dp[0]=0;
    for (int i = 1; i < n; ++i)
    {
        if (i >= 1)
        {
            dp[i] = min(dp[i], abs(arr[i] - arr[i - 1]) + dp[i - 1]);
        }
        if (i >= 3)
        {
            dp[i] = min(dp[i], abs(arr[i] - arr[i - 3]) + dp[i - 3]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
}
int main()
{
    vector<int> arr = {10, 30, 100, 20, 40, 10};
    // cout << recursion(arr, 0, arr[0]);
    tabulation(arr);
}
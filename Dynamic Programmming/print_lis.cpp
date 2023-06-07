#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {2, 3, 6, 4, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> dp(n); // 2D -Vector
    dp[0].push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i].size() < dp[j].size() + 1)
            {
                // cout << "i=" << i << " " << dp[i].size() << " " << dp[j].size() << endl;
                dp[i] = dp[j];
                // cout << "i= "<<i<< dp[i] << endl;
            }
        }
        dp[i].push_back(arr[i]);
    }
    vector<int> max = dp[0];
    for (vector<int> x : dp)
    {
        if (x.size() > max.size())
        {
            max = x;
        }
    }
    for (int x : max)
    {
        cout << x << " ";
    }
}
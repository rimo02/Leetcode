#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {7, 3, 1, 2, 3};
    int n = arr.size();
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = arr[i];
        int j = i + arr[i];
        if (j < n)
            dp[i] += dp[j];
    }
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
}
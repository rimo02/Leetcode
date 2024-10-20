#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 1e9); // Initialize dp array with a large value (infinity)
    dp[0] = 0;                  // Base case: 0 coins are needed to make sum 0

    for (int j = 1; j <= x; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (coins[i] <= j)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
    }

    if (dp[x] != 1e9)
    {
        cout << dp[x] << endl; // Minimum number of coins needed to make sum x
    }
    else
    {
        cout << -1 << endl; // If no combination can make sum x, return -1
    }

    return 0;
}

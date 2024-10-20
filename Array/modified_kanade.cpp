#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution
{
public:
    const ll MOD = 1e9 + 7;
    int kadane(vector<int> arr)
    {
        ll ans = 0, sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            sum = sum % MOD;
            if (sum < 0)
            {
                sum = 0;
            }
            ans = max(ans, sum);
            ans = ans % MOD;
        }
        return ans % MOD;
    }
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        if (k == 1)
        {
            return kadane(arr);
        }
        ll sum = accumulate(arr.begin(), arr.end(), 0ll) % MOD;
        arr.insert(arr.end(), arr.begin(), arr.end());
        ll total = kadane(arr) % MOD;
        if (sum <= 0)
            return total;
        else
            return (total + ((k - 2) * sum % MOD) % MOD) % MOD;
    }
};
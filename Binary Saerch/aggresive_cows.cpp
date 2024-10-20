#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &stalls, int mid, int k)
    {
        int n = stalls.size();
        int cnt = 1;
        int last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= mid)
            {
                cnt++;
                last = stalls[i];
            }
            if (cnt >= k)
                return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls)
    {

        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(stalls, mid, k))
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return high;
        // Note: It is always the opposite polarity. Initially the pointer ‘high’ was in the ‘not-possible’ half and so it ends up in the ‘possible’ half. Similarly, ‘low’ was initially in the ‘possible’ part and it ends up in the ‘not-possible’ part.
    }
};
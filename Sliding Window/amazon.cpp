#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {3, 4, 4, 9, 5};
    int n = arr.size();
    int right = 0, diff = 0;
    while (right < n)
    {
        if (right > 0 && arr[right] <= arr[right - 1])
        {
            diff = arr[right - 1] - arr[right];
            arr[right] += diff;
        }
        right++;
    }
}
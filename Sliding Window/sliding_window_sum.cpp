#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {0, 6, 5, 2, 2, 5, 1, 9, 4};
    int k = 5;
    int n = arr.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    int res = INT16_MIN;
    for (int i = k; i < n; i++)
    {
        res = max(res, prefixSum[i] - prefixSum[i - k]);
    }
    cout << "Maximum sum = " << res << endl;
}
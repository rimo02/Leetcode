#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {5,4,3,2,1};
    /*
    There are two types of subarrays
    1 - beginning with arr[i] -> total (n-i) subarrays
    2 - not beginning with arr[i] -> total (n-i) *i subarrays
    {1,2,3,4} - not including 3 there will be subarrays like {1,2,3},{1,2,3,4} , {2,3},{2,3,4} .ie i * (n-i)
    simplifying it gets (n-i)*(i+1)
    */
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (n - i) * (i + 1) * arr[i];
    }
    cout << "Sum=" << sum << endl;
}
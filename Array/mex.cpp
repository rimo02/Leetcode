// find maximal non excluded array element
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {-5, -3, -1, 0};
    // (nlogn)
    // set<int> st(arr.begin(), arr.end());
    // int res = 0;
    // while (st.find(res) != st.end())
    // {
    //     res++;
    // }
    // cout << res;
    vector<bool> used(100, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0)
            used[arr[i]] = true;
    }
    int res = 0;
    while (used[res])
        res++;
    cout << res;
}
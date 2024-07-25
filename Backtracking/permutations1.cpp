#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void dfs(vector<int> arr, int idx, int n)
    {
        if (idx == n)
        {
            ans.push_back(arr);
            return;
        }
        for (int j = idx; j < n; j++)
        {
            if (j != idx && arr[idx] == arr[j])
                continue;
            swap(arr[j], arr[idx]);
            dfs(arr, idx + 1, n);
        }
    }
    void findPermutations(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        dfs(arr, 0, arr.size());
        for (auto el : ans)
        {
            for (auto it : el)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    vector<int> arr = {2, 2, 1, 1};
    Solution S;
    S.findPermutations(arr);
}
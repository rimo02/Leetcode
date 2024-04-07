#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    void dfs(vector<int> arr, int idx)
    {
        if (idx >= arr.size())
        {
            ans.push_back(arr);
            return;
        }
        for (int j = idx; j < arr.size(); j++)
        {
            swap(arr[j],arr[idx]);
            dfs(arr, idx + 1);
        }
    }
    void findPermutations(int n)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
            arr.push_back(i);
        dfs(arr, 0);
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
    Solution S;
    int n;
    cout << "Enter n:";
    cin >> n;
    S.findPermutations(n);
}
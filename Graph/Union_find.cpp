// Number of provinces

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> v;
    int parent(int x)
    {
        if (v[x] == -1)
            return x;
        return v[x] = parent(v[x]);
    }
    void _union(int i, int j)
    {
        cout << "i = " << i << "  j = " << j << endl;
        int p_a = parent(i);
        int p_b = parent(j);
        cout << p_a << "  " << p_b << endl;
        if (p_a == p_b)
            return;
        v[p_a] = p_b;
        for(auto &it: v) cout<<it<<" ";
        cout<<endl;
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        v.resize(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    _union(i, j);
                }
            }
        }
        int c = 0;
        cout << "\n";
        return c;
    }
};
int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution S;
    cout << S.findCircleNum(isConnected);
}
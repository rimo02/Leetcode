#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dfs(vector<vector<pair<int, int>>> &adj, int s, int node, int first, int wt, int ans)
    {
        if (wt % s == 0)
        {
            ans++;
        }
        for (auto it : adj[first])
        {
            if (first == node)
            {
                continue;
            }
            dfs(adj, s, node, first, wt + it.second, ans);
        }
    }
    int cal(vector<vector<pair<int, int>>> &adj, int s, int c)
    {
        vector<int> vec;
        int toal = 0;
        for (auto x : adj[c])
        {
            int ans = 0;
            dfs(adj, s, c, x.first, x.second, ans);
            vec.push_back(ans);
            toal += ans;
        }
        int ans = 0;
        for(auto ele: vec)
        {
            toal -= ele;
            ans += ele * toal;
        }
        return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto ele : edges)
        {
            adj[ele[0]].push_back({ele[1], ele[2]});
            adj[ele[1]].push_back({ele[0], ele[2]});
        }
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++)
        {
            count[i] += cal(adj, signalSpeed, i);
        }
        return count;
    }
};
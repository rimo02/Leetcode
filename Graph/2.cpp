#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, int par, int s, int wt, int &ans, vector<vector<pair<int, int>>> &adj)
    {
        if (wt % s == 0)
        {
            ans++;
        }
        for (pair<int, int> x : adj[node])
        {
            if (x.first == par)
            {
                continue;
            }
            dfs(x.first, node, s, x.second + wt, ans, adj);
        }
    }
    int fn(int node, int s, vector<vector<pair<int, int>>> &adj)
    {
        vector<int> v;
        int tsum = 0;
        for (pair<int, int> x : adj[node])
        {
            int ans = 0;
            dfs(x.first, node, s, x.second, ans, adj);
            v.push_back(ans);
            tsum += ans;
        }
        int res = 0;
        for (int x : v)
        {
            tsum -= x;
            res += x * tsum;
        }
        return res;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int s)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto x : edges)
        {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            res[i] += fn(i, s, adj);
            cout << res[i] << endl;
        }
        return res;
    }
};
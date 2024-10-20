#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validColor(vector<int> adj[], int node, vector<int> &color, int c)
    {
        for (auto &it : adj[node])
        {
            if (color[it] == c)
                return false;
        }
        return true;
    }

    bool solve(vector<int> adj[], int node, int n, vector<int> &color)
    {
        if (node > n)
            return true;

        for (int i = 1; i <= 4; i++)
        {
            if (validColor(adj, node, color, i))
            {
                color[node] = i;
                if (solve(adj, node + 1, n, color))
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<int> adj[n + 1];
        vector<int> color(n + 1, 0);
        for (auto &it : paths)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int node = 1;
        solve(adj, node, n, color);
        return vector<int>(color.begin() + 1, color.end());
    }
};

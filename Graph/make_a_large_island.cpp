#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
public:
    vector<int> parent, rank, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int x) // path compression
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }
    void UnionByRank(int u, int v)
    {
        int p_u = findParent(u);
        int p_v = findParent(v);
        if (p_u == p_v)
            return;
        if (rank[p_u] < rank[p_v])
        {
            parent[p_u] = p_v;
        }
        else if (rank[p_u] > rank[p_v])
        {
            parent[p_v] = p_u;
        }
        else
        {
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int p_u = findParent(u);
        int p_v = findParent(v);
        if (p_u == p_v)
            return;
        if (size[p_u] < size[p_v])
        {
            parent[p_u] = p_v;
            size[p_v] += size[p_u];
        }
        else
        {
            parent[p_v] = p_u;
            size[p_u] += size[p_v];
        }
    }
};
class Solution
{
public:
    bool isValid(int r, int c, int n)
    {
        if (r < 0 || r >= n || c < 0 || c >= n)
            return false;
        else
            return true;
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int k = 0; k < 4; k++)
                {
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                    {
                        int nodeno = i * n + j;
                        int adjnode = n * newr + newc;
                        ds.UnionBySize(nodeno, adjnode);
                    }
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int k = 0; k < 4; k++)
                {
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1)
                    {
                        int adjnode = n * newr + newc;
                        components.insert(ds.findParent(adjnode));
                    }
                }
                int total = 0;
                for (auto it : components)
                {
                    total += ds.size[it];
                }
                maxi = max(maxi, total + 1);
            }
        }
        for (int i = 0; i < n * n; i++)
        {
            maxi = max(maxi, ds.size[i]);
        }
        return maxi;
    }
};
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> parent, rank, size;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet ds(n);
        sort(accounts.begin(), accounts.end());
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mp.find(mail) != mp.end())
                {
                    ds.UnionBySize(i, mp[mail]);
                }
                else
                {
                    mp[mail] = i;
                }
            }
        }
        vector<string> email[n];
        for (auto it : mp)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            email[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (email[i].size() == 0)
                continue;
            sort(email[i].begin(), email[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : email[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
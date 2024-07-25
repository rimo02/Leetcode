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
int main()
{
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);
    if (ds.findParent(3) == ds.findParent(7))
        cout << "Same\n";
    else
        cout << "Not Same\n";
}
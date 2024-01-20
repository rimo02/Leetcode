#include <iostream>
#include <vector>
#include <pair>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<pair<int, int>> ans;
    bool static cmp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.second != p2.second)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
    void dijkstras(vector<pair<int, int>> adj, int src, int n, int distanceThreshold)
    {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto ele : adj[u])
            {
                int v = ele.first;
                int wt = ele.second;
                if (dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (i != src && dist[i] <= distanceThreshold)
            {
                count++;
            }
        }
        ans.push_back({src, count});
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        for (int i = 0; i < n; i++)
        {
            dijkstras(adj, i, n, distanceThreshold);
        }
        sort(ans.begin(), ans.end(), cmp);
        return ans[0].first;
    }
};
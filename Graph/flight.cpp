#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// chepest flight within k stops
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    // return dijkstras(n,flights,src,dst,k);
    vector<vector<pair<int, int>>> adj(n);
    for (auto f : flights)
    {
        adj[f[0]].push_back({f[1], f[2]});
    }
    vector<int> dist(n, INT16_MAX);
    dist[src] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {src, 0}});
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int stops = t.first;
        int u = t.second.first;
        int d = t.second.second;
        if (stops > k)
            continue;
        for (auto it : adj[u])
        {
            int v = it.first;
            int weight = it.second;
            dist[v] = min(dist[v], weight + dist[u]);
            pq.push({stops + 1, {v, dist[v]}});
        }
    }
    return dist[dst] == INT16_MAX ? -1 : dist[dst];
}
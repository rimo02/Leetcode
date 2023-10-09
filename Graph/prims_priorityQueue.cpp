#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define V 9
typedef pair<int, int> pii;

int spanningTree(int v, int e, int edges[][3])
{
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V, false);
    int res = 0;
    pq.push({0, 0}); //{weight,node}
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int wt = p.first;
        int u = p.second;
        if (visited[u])
            continue;
        visited[u] = true;
        res += wt;
        for (auto v : adj[u])
        {
            if (!visited[v.first])
            {
                pq.push({v.second, v.first});
            }
        }
    }
    return res;
}

int main()
{
    int graph[][3] = {{0, 1, 4},  //
                      {0, 7, 8},  //
                      {1, 0, 4},  //
                      {1, 2, 8},  //
                      {1, 7, 11}, //
                      {2, 1, 8},  //
                      {2, 3, 7},  //
                      {2, 8, 2},  //
                      {3, 2, 7},  //
                      {3, 4, 9},  //
                      {3, 5, 14}, //
                      {4, 3, 9},  //
                      {4, 5, 10}, //
                      {5, 3, 14}, //
                      {5, 4, 10}, //
                      {5, 2, 4},  //
                      {5, 6, 2},  //
                      {6, 5, 2},  //
                      {6, 7, 1},  //
                      {6, 8, 6},  //
                      {7, 6, 1},
                      {7, 0, 8},
                      {7, 1, 11},
                      {7, 8, 7},
                      {8, 2, 2},
                      {8, 7, 7},
                      {8, 6, 6}};
    cout << spanningTree(9, 27, graph) << endl;
    return 0;
}

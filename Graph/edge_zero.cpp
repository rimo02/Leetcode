// You are given a graph , weighted and directed. an integer k and source and target nodes , find the shortest path from source to destination if you are allowed to make atmost k nodes 0
// Approach - DFS through the whole graph store all the possible paths from source to destnation and then sort eacch path in descending order, then make first k paths 0 and then keep on checking max path weight
#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<pair<int, int>> *adj;
    vector<bool> visited;
    vector<vector<int>> all_paths;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
        visited.resize(V);
    }
    // undirected graph
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
    }
    void dfs(int src, int dst, vector<int> &temp)
    {
        if (src == dst)
        {
            all_paths.push_back(temp);
        }
        visited[src] = true;
        for (auto it : adj[src])
        {
            int v = it.first;
            int w = it.second;
            if (!visited[v])
            {
                temp.push_back(w);
                dfs(v, dst, temp);
                temp.pop_back();
            }
        }
        visited[src] = false;
    }
    int shortestPath_After_Making_K_Zero(int k, int src, int dest)
    {
        vector<int> temp;
        dfs(src, dest, temp);
        int mini = 1e9;
        for (auto path : all_paths)
        {
            if (path.size() <= k)
                return 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            int total = 0;
            int ksum = 0;
            for (int i = 0; i < path.size(); i++)
            {
                total += path[i];
                pq.push(path[i]);
                if (pq.size() > k)
                {
                    ksum += pq.top();
                    pq.pop();
                }
            }
            mini = min(mini, ksum);
        }
        return mini;
    }
};
int main()
{
    // int V = 5;
    // Graph g(V);
    // g.addEdge(0, 1, 5);
    // g.addEdge(0, 3, 2);
    // g.addEdge(1, 2, 5);
    // g.addEdge(3, 1, 2);
    // g.addEdge(1, 4, 1);
    // g.addEdge(4, 2, 1);
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    int k = 1;
    int ans = g.shortestPath_After_Making_K_Zero(k, 0, 8);
    cout << "The shorted path = " << ans << endl;
}

// Time Complexity
/// dfs = n ^ n
// minheap = nlogk * const
// tc = n^n*nlogk
#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    // directed graph
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void khans()
    {
        vector<int> indegree(this->V, 0);
        for (int u = 0; u < V; u++)
        {
            for (auto v : adj[u])
            {
                indegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> res;
        int cnt = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (auto v : adj[u])
            {
                if (--indegree[v] == 0)
                {
                    q.push(v);
                }
            }
            cnt++;
        }

        if (cnt != V)
        {
            cout << "There exist a cycle in the graph" << endl;
            return;
        }
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
};
int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.khans();
}
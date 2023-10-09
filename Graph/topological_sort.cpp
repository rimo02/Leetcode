#include <iostream>
#include <stack>
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
    void dfs(int v, bool visited[], stack<int> &stk)
    {
        visited[v] = true;
        for (auto i : adj[v])
        {
            if (!visited[i])
                dfs(i, visited, stk);
        }
        stk.push(v);
    }
    void topologicalSort()
    {
        stack<int> stk;
        bool *visited = new bool[this->V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                dfs(i, visited, stk);
        }
        while (!stk.empty())
        {
            int ele = stk.top();
            stk.pop();
            cout << ele << " ";
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
    g.topologicalSort();
}
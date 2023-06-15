#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<list<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void printGraph()
    {
        for (int v = 0; v < V; v++)
        {
            cout << "Adjacency of " << v << ":";
            for (auto x : adj[v])
            {
                cout << "--> " << x;
            }
            cout << endl;
        }
    }

    bool checkCycleUntil(int v, bool visited[], bool stack[])
    {
        cout << "Cycle =" << v << endl;
        if (visited[v] == false)
        {
            visited[v] = true;
            stack[v] = true;
            list<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); i++)
            {
                if (!visited[*i]) //! had 7 previously visited? No
                {
                    if (checkCycleUntil(*i, visited, stack))
                        return true;
                }
                else if (stack[*i])
                {
                    cout << v << " " << *i << endl;
                    return true;
                }
            }
        }
        stack[v] = false;
        return false;
    }

    bool isCircular(int V)
    {
        bool visited[V];
        bool stack[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            stack[i] = false;
        }
        for (int i = 0; i < V; i++)
        {
            if (checkCycleUntil(i, visited, stack))
            {
                cout << "Cycle starting with " << i << endl;
                return true;
            }
        }
        return false;
    }
};
int main()
{
    int V = 10;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(4, 5);
    g.addEdge(6, 5);
    g.addEdge(7, 8);
    g.addEdge(7, 2);
    g.addEdge(8, 9);
    g.addEdge(9, 7);
    if (g.isCircular(V))
    {
        cout << "There is a cycle present";
    }
    else
    {
        cout << "There is no cycle present";
    }
}
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int, list<int>> adj;
    map<int, bool> visited;

public:
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void printGraph()
    {
        for (auto &pair : adj)
        {
            int vertex = pair.first;
            list<int> &neighbours = pair.second;
            cout << "\nVertex " << vertex << " is connected to:";
            for (int neighbour : neighbours)
            {
                cout << " -->" << neighbour;
            }
        }
    }
    void DFS(int v)
    {
        visited[v] = true;
        cout << v << " ";
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i])
            {
                DFS(*i);
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();

    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 0):";
    g.DFS(1);
}
#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); //Since it is an undirected graph
}
void printGraph(vector<int> graph[],int V)
{
    for(int v=0;v<V;v++)
    {
        cout<<"Adjacency of "<<v<<":";
        for(auto x: graph[v])
        {
            cout<<"--> "<<x;
        }
        cout<<endl;
    }
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printGraph(adj, V);
}
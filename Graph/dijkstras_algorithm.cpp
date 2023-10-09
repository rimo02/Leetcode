// gfg
#include <iostream>
#include <vector>
using namespace std;
#define V 9
int minDist(bool spt[], int dist[])
{
    int min = INT16_MAX, minIdx;
    for (int v = 0; v < V; v++)
    {
        if (spt[v] == false && dist[v] <= min)
        {
            min = dist[v];
            minIdx = v;
        }
    }
    return minIdx; 
}
void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}
void dijkstra(int graph[V][V], int start)
{
    bool spt[V];
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        spt[i] = false;
        dist[i] = INT16_MAX;
    }
    dist[start] = 0;
    for (int i = 0; i < V; i++)
    {
        int u = minDist(spt, dist);
        spt[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!spt[v] && graph[u][v] && dist[u] != INT16_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}}; // adjacency matrix
    dijkstra(graph, 0);
}
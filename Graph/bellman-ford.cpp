#include <iostream>
using namespace std;
struct Edge
{
    int src, dst, weight;
};
struct Graph
{
    int V, E;
    struct Edge *edge;
};
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
};
void printSolution(int dist[], int V)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}
void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT16_MAX;
    }
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++) // relaxing all vertices v-1
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dst;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT16_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }
    printSolution(dist, V);

    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dst;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT16_MAX && dist[u] + weight < dist[v])
        {
            printf("%d %d\n", u, v);
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply
                    // return
        }
    }
}
int main()
{
    int V = 6;
    int E = 7;
    struct Graph *graph = createGraph(V, E);
    // A-B
    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;
    graph->edge[0].weight = 5;
    // B-C
    graph->edge[1].src = 1;
    graph->edge[1].dst = 2;
    graph->edge[1].weight = 1;
    // B-D
    graph->edge[2].src = 1;
    graph->edge[2].dst = 3;
    graph->edge[2].weight = 2;
    // C-E
    graph->edge[3].src = 2;
    graph->edge[3].dst = 4;
    graph->edge[3].weight = 1;
    // D-F
    graph->edge[4].src = 3;
    graph->edge[4].dst = 5;
    graph->edge[4].weight = 2;
    // E-D
    graph->edge[5].src = 4;
    graph->edge[5].dst = 3;
    graph->edge[5].weight = -1;
    // F-E
    graph->edge[6].src = 5;
    graph->edge[6].dst = 4;
    graph->edge[6].weight = -3;

    BellmanFord(graph, 0);
}
#include <iostream>
using namespace std;
#define V 5
int minKey(int key[], bool mstSet[])
{
    int min = INT16_MAX, min_idx;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min) // should be false else there will be a circular loop
        {
            min = key[v];
            min_idx = v;
        }
    }
    return min_idx;
}
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n"
         << endl;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << "\t" << graph[i][parent[i]] << endl;
    }
}
void primAlgo(int graph[V][V])
{
    int parent[V];  // Array to store the constructed MST
    int key[V];     // Key Values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices in MST
    for (int i = 0; i < V; i++)
        key[i] = INT16_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}
int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // Print the solution
    primAlgo(graph);
    return 0;
}
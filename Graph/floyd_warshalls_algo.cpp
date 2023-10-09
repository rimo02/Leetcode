#include <iostream>
using namespace std;
#define V 4
void floydWarshall(int graph[V][V])
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (graph[i][j] > (graph[i][k] + graph[k][j]) && graph[k][j] != INT16_MAX && graph[i][k] != INT16_MAX)
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
int main()
{
    int graph[V][V] = {
        {0, 3, INT16_MAX, 7},
        {8, 0, 2, INT16_MAX},
        {5, INT16_MAX, 0, 1},
        {2, INT16_MAX, INT16_MAX, 0}};
}
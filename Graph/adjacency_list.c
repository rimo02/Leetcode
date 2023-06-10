#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Dest;
    struct Node *Next;
};
struct AdjList
{
    struct Node *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dst)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->Dest = dst;
    node->Next = NULL;

    struct Node *check = NULL;
    if (graph->array[src].head == NULL)
    {
        graph->array[src].head = node;
    }
    else
    {
        check = graph->array[src].head;
        while (check->Next != NULL)
        {
            check = check->Next;
        }
        check->Next = node;
    }
}
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->V; v++)
    {
        struct Node *arr = graph->array[v].head;
        printf("\nAdjacency list of vertex %d:", v);
        while (arr)
        {
            printf("--> %d", arr->Dest);
            arr=arr->Next;
        }
    }
}
int main()
{
    int V = 5;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 3);
    printGraph(graph);
}

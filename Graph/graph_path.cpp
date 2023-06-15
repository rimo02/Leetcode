#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int current, int end)
    {
        if (current == end)
            return true;
        if (visited[current])
            return false;
        visited[current] = 1;
        for (int i = 0; i < graph[current].size(); i++)
        {
            cout << graph[current][i] << endl;
            if (dfs(graph, visited, graph[current][i], end))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        return dfs(graph, visited, source, destination);
    }
};
int main()
{
    int n = 6;
    int source = 0;
    int destination = 5;
    vector<vector<int>> edges{
        {0, 1},
        {0, 2},
        {3, 5},
        {5, 4},
        {4, 3}};
    Solution g;
    bool b = g.validPath(n, edges, source, destination);
    cout << b;
    // int n = 3;
    // int source = 0;
    // int destination = 2;
    // vector<vector<int>> edges{
    //     {0, 1},
    //     {1, 2},
    //     {2, 0}};
    // Solution g;
    // bool b = g.validPath(n, edges, source, destination);
    // cout << b;
}
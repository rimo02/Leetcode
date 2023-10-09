
// You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

// You are given two arrays redEdges and blueEdges where:

// redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
// blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
// Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

// Example 1:
// Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
// Output: [0,1,-1]

// Example 2:
// Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
// Output: [0,1,-1]

#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> res(n, -1);
        res[0] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : redEdges)
        {
            adj[it[0]].push_back({it[1], 0});
        }
        for (auto it : blueEdges)
        {
            adj[it[0]].push_back({it[1], 1});
        }
        queue<vector<int>> q;
        q.push({0, 0, -1}); // {node,distance,color}
        vector<vector<bool>> visited(n, vector<bool>(2));
        visited[0][0] = visited[0][0] = true;

        while (!q.empty())
        {
            auto it = q.front();
            int u = it[0];
            int d = it[1];
            int prevColor = it[2];
            q.pop();
            for (auto &[v, edgeColor] : adj[u])
            {
                if (!visited[v][edgeColor] && edgeColor != prevColor)
                {
                    visited[v][edgeColor] = true;
                    q.push({v, 1 + d, edgeColor});
                    if (res[v] == -1)
                    {
                        res[v] = d + 1;
                    }
                }
            }
        }
        return res;
    }
};
int main()
{
    int n = 5;
    vector<vector<int>> red{{0, 1}, {3, 4}};
    vector<vector<int>> blue{{0, 3}, {1, 2}, {2, 3}};
    Solution S;
    vector<int> arr = S.shortestAlternatingPaths(n, red, blue);
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
}
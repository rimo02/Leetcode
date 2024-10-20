#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<bool>> &vis, vector<pair<int, int>> &vec, int i, int j)
    {
        int x = r - i;
        int y = c - j;
        vec.push_back({x, y});
        vis[r][c] = 1;
        int m = grid.size();
        int n = grid[0].size();
        int dirx[] = {-1, 0, 1, 0};
        int diry[] = {0, -1, 0, 1};
        for (int p = 0; p < 4; p++)
        {
            int newx = dirx[p] + r;
            int newy = diry[p] + c;
            if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1 && !vis[newx][newy])
            {
                dfs(newx, newy, grid, vis, vec, i, j);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

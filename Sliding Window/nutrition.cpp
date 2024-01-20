#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Function to perform DFS and count good colorings
void dfs(int node, int parent, vector<vector<int>> &adj_list, vector<vector<int>> &dp)
{
    // Initialize counts for red and blue colors
    int red_count = 1;
    int blue_count = 1;

    // Iterate through children of the current node
    for (int child : adj_list[node])
    {
        if (child != parent)
        {
            dfs(child, node, adj_list, dp);
            // Accumulate counts for red and blue colors from children
            red_count = (1LL * red_count * (dp[child][0] + dp[child][1])) % MOD;
            blue_count = (1LL * blue_count * (dp[child][0] + dp[child][1])) % MOD;
        }
    }

    // Store counts of red and blue for the current node
    dp[node][0] = red_count;
    dp[node][1] = blue_count;
}

// Function to solve the problem
void solve()
{
    int T;
    cin >> T; // Number of test cases

    while (T--)
    {
        int N;
        cin >> N; // Number of nodes in the tree

        vector<vector<int>> adj_list(N + 1);
        vector<vector<int>> dp(N + 1, vector<int>(2, 0));

        // Create adjacency list to represent the tree
        for (int i = 1; i <= N - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        // Perform DFS starting from root node 1
        dfs(1, 0, adj_list, dp);

        // Calculate total number of good colorings modulo 10^9 + 7
        int total_good_colorings = (dp[1][0] + dp[1][1]) % MOD;
        cout << total_good_colorings << endl;
    }
}

int main()
{
    solve();
    return 0;
}

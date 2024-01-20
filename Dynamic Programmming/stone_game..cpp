// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation:
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.

#include <iostream>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
public:
    int dfs(vector<int> &piles, int i, int j, int turn)
    {
        if (i > j)
            return false;
        if (turn)
        {
            int alice1 = dfs(piles, i + 1, j, turn - 1) + piles[i];
            int alice2 = dfs(piles, i, j - 1, turn - 1) + piles[j];
            return max(alice1, alice2);
        }
        int bob1 = dfs(piles, i + 1, j, turn + 1) + piles[i];
        int bob2 = dfs(piles, i, j - 1, turn + 1) + piles[j];
        return max(bob1, bob2);
    }
    int tabulation(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        for (int i = 0; i < n; i++)
            dp[i][i] = {piles[i], 0};
        // for a single pile the best alice can do is choose only the single pile
        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < n - j; i++)
            {
                dp[i][i + j].first = max(dp[i + 1][j + i].second + piles[i], dp[i][j + i - 1].second + piles[i + j]);
                dp[i][i + j].second = max(dp[i + 1][i + j].first, dp[i][i + j - 1].first);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "(" << dp[i][j].first << "," << dp[i][j].second << ")"
                     << "\t";
            }
            cout << endl;
        }
        cout << endl;
        return dp[0][n - 1].first;
    }
    bool stoneGame(vector<int> &piles)
    {
        // return dfs(piles,0,piles.size()-1,1);
        return tabulation(piles);
    }
};
int main()
{
    Solution S;
    vector<int> piles = {3, 9, 1, 2};
    cout << S.stoneGame(piles);
}
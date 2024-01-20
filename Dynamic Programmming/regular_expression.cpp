#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int dfs(string s, string p, int i, int j)
    {
        if (j == p.size())
            return i == s.size();
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*')
        {
            return (dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j)));
        }
        else
            return (match && dfs(s, p, i + 1, j + 1));
    }
    int tabulation(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = 1; // case of single string
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
    bool isMatch(string s, string p)
    {
        // return dfs(s,p,0,0);
        return tabulation(s, p);
    }
};
int main()
{
    string s = "abbbbbbbef";
    string p = "ab*e.";
    Solution S;
    cout << S.isMatch(s, p);
}
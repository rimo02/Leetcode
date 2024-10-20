#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string bruteforce(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        string dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = "";
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size()
                                   ? dp[i - 1][j]
                                   : dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
    string optimal(string str1, string str2)
    {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string ans = "";
        int len = dp[m][n];
        for (int i = 0; i < len; i++)
            ans += "$";
        int i = m, j = n;
        int idx = len - 1;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans[idx--] = str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};
int main()
{
    Solution S;
    string s1 = "abac", s2 = "cab";
    cout << S.optimal(s1, s2);
}
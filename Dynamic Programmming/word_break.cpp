#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // only 1 parameter is changing therfore we will be neeeding only 1D dp
    bool dfs(string s, unordered_map<string, int> &mp, int i)
    {
        if (i >= s.size())
            return true;
        for (int j = i; j < s.size(); j++)
        {
            string str = s.substr(i, j - i + 1);
            if (mp[str] && dfs(s, mp, j + 1))
            {
                return true;
            }
        }
        return false;
    }
    bool tabulation(string s, unordered_map<string, int> &mp)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j])
                {
                    string wrd = s.substr(j, i - j);
                    if (mp.find(wrd) != mp.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> mp;
        for (auto word : wordDict)
            mp[word]++;
        // return dfs(s, mp, 0);
        return tabulation(s, mp);
    }
};
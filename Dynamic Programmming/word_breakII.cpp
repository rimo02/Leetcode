#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");
        for (int i = 1; i <= n; i++) {
            vector<string> temp;
            for (int j = 0; j < i; j++) {
                string str = s.substr(j, i - j);
                if (st.find(str) != st.end()) {
                    for (auto& it : dp[j]) {
                        temp.push_back((it + (it.empty() ? "" : " ") + str));
                    }
                }
            }
            dp[i] = temp;
        }
        return dp[n];
    }
}
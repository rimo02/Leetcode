#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> ans;
    void dfs(vector<string> words, int idx)
    {
        if (idx >= words.size())
        {
            string s = "";
            for (auto word : words)
                s += word;
            ans.push_back(s);
            return;
        }
        for (int i = idx; i < words.size(); i++)
        {
            swap(words[idx], words[i]);
            dfs(words, idx + 1);
            swap(words[idx], words[i]);
        }
    }
    void findPermutations(vector<string> words)
    {
        dfs(words, 0);
        for (auto str : ans)
        {
            cout << str << endl;
        }
        cout << endl;
    }
};
int main()
{
    Solution S;
    vector<string> words = {"ab", "bc", "ca"};
    S.findPermutations(words);
    return 0;
}
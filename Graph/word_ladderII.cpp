#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
                word[i] = original;
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList)
    {
        b = beginWord;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push({beginWord});
        mp[beginWord] = 1;
        st.erase(beginWord);
        int size = beginWord.size();
        while (!q.empty())
        {
            string word = q.front();
            if (word == endWord)
            {
                break;
            }
            int steps = mp[word];
            q.pop();
            for (int i = 0; i < size; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
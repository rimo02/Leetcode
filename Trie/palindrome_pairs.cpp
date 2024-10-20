#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    vector<int> restIsPalindrome;
    int flag = -1;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void setpalin(int i)
    {
        restIsPalindrome.push_back(i);
    }
    void setend(int idx)
    {
        flag = idx;
    }
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string &word, int idx)
    {
        int n = word.size();
        Node *node = root;
        for (int i = n - 1; i >= 0; i--)
        {
            if (isPalindrome(word, 0, i))
            {
                node->setpalin(idx);
            }
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setend(idx);
        return;
    }
    void search(string &word, int idx, vector<vector<int>> &res)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (node->flag != -1 && isPalindrome(word, i, n - 1)) // one string is completed in trie and the rest of current word is palindrome eg - s and sll
            {
                res.push_back({idx, node->flag});
            }
            if (!node->containsKey(word[i]))
                return;
            node = node->get(word[i]);
        }
        // eg abcd and dcba / aaaa
        if (node->flag != -1 & node->flag != idx)
        {
            res.push_back({idx, node->flag});
        }
        for (int j : node->restIsPalindrome)
        {
            res.push_back({idx, j});
        }
    }
    bool isPalindrome(string &s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};
class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        Trie trie;
        for (int i = 0; i < n; i++)
        {
            trie.insert(words[i], i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            trie.search(words[i], i, ans);
        }
        return ans;
    }
};
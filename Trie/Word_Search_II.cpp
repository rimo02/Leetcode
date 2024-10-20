#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (

            links[ch - 'a'] != NULL);
    }
    Node *get(char ch) { return links[ch - 'a']; }
    void put(char ch, Node *node) { links[ch - 'a'] = node; }
    bool getEnd() { return flag; }
    void increaseEnd() { flag = true; }
};
class Trie
{

public:
    Node *root;
    Trie() { root = new Node(); }
    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->increaseEnd();
    }
    void search(vector<vector<char>> &board, int r, int c,
                vector<vector<bool>> &visited, set<string> &st, string current,
                Node *node)
    {
        int m = board.size();
        int n = board[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c])
            return;
        char ch = board[r][c];
        if (!node->containsKey(ch))
            return;
        current += ch;
        node = node->get(ch);
        if (node->getEnd() == true)
        {
            st.insert(current);
            // return;
        }
        visited[r][c] = true;
        search(board, r + 1, c, visited, st, current, node);
        search(board, r, c + 1, visited, st, current, node);
        search(board, r - 1, c, visited, st, current, node);
        search(board, r, c - 1, visited, st, current, node);
        visited[r][c] = false;
        current.pop_back();
    }
};
class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words)
    {
        Trie trie;
        for (auto &it : words)
        {
            trie.insert(it);
        }
        int m = board.size();
        int n = board[0].size();
        set<string> st;
        string cuurent = "";
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Node *node = trie.root;
                trie.search(board, i, j, visited, st, cuurent, node);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};
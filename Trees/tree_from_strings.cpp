#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
class Solution
{
public:
    Node *dfs(string s)
    {
        // 445(2(3)(1))(6(5))
        if (s.empty())
            return nullptr;

        int first = s.find('('); // first occurence of left
        Node *root;
        if (first == string::npos)
        {
            root = new Node(stoi(s));
        }
        else
        {
            root = new Node(stoi(s.substr(0, first)));
            int balance = 0;
            int child = first;
            for (int i = first; i < s.size(); i++)
            {
                if (s[i] == '(')
                {
                    balance++;
                }
                else if (s[i] == ')')
                {
                    balance--;
                }
                if (balance == 0)
                {
                    if (child == first)
                    {
                        root->left = dfs(s.substr(first + 1, i - first - 1));
                        child = i + 1;
                    }
                    else
                    {
                        root->right = dfs(s.substr(child + 1, i - child - 1));
                    }
                }
            }
        }
        return root;
    }
    Node *treeFromString(string str)
    {
        return dfs(str);
    }
};
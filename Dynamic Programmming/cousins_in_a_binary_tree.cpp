#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {-1, 0}});
        pair<int, int> px;
        pair<int, int> py;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode *temp = q.front().first;
                int parent = q.front().second.first;
                int depth = q.front().second.second;
                q.pop();
                if (temp->val == x)
                    px = {parent, depth};
                if (temp->val == y)
                    py = {parent, depth};
                if (temp->left)
                    q.push({temp->left, {temp->val, depth + 1}});
                if (temp->right)
                    q.push({temp->right, {temp->val, depth + 1}});
            }
        }
        if (px.first != py.first && px.second == py.second)
            return true;
        return false;
    }
};
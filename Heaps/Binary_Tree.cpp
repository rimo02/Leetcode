#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class CBTree
{
public:
    TreeNode *root;
    CBTree()
    {
        root = nullptr;
    }
    void insert(int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left == nullptr)
            {
                current->left = new TreeNode(val);
                break;
            }
            else
            {
                q.push(current->left);
            }
            if (current->right == nullptr)
            {
                current->right = new TreeNode(val);
                break;
            }
            else
            {
                q.push(current->left);
            }
        }
    }
    void levelOrderTraversal()
    {
        if (root == nullptr)
            return;
        queue<TreeNode *> q;
        q.push(root);
        cout << "The level order traversal = ";
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
};
int main()
{
    CBTree cbt;
    cbt.insert(1);
    cbt.insert(2);
    cbt.insert(3);
    cbt.insert(4);
    cbt.insert(5);
    cbt.levelOrderTraversal();
}

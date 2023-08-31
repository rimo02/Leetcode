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
class MinHeap
{
public:
    TreeNode *root;
    MinHeap()
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
                q.push(current->right);
            }
        }
    }
    void makeHeap()
    {
        heapify(root);
    }
    void heapify(TreeNode *root)
    {
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        TreeNode *smallest = root;
        if (left != nullptr && left->data < smallest->data)
        {
            smallest = left;
        }
        if (right != nullptr && right->data < smallest->data)
        {
            smallest = right;
        }
        if (smallest != root)
        {
            swap(root->data, smallest->data);
            heapify(smallest->left);
            heapify(smallest->right);
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
    MinHeap minh;
    minh.insert(5);
    minh.insert(2);
    minh.insert(8);
    minh.insert(4);
    minh.insert(7);
    cout << "\nBefore heapification" << endl;
    minh.levelOrderTraversal();
    minh.makeHeap();
    cout << "\nAfter heapification" << endl;
    minh.levelOrderTraversal();
}

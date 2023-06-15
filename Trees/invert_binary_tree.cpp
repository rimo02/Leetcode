#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Tree
{
public:
    Node *Root;
    Tree()
    {
        Root = NULL;
    }
    Node *buildtree(Node *Root, int val)
    {
        if (Root == NULL)
        {
            Root = new Node(val);
        }
        else if (val < Root->data)
        {
            Root->left = buildtree(Root->left, val);
        }
        else
        {
            Root->right = buildtree(Root->right, val);
        }
        return Root;
    }
    void inorderRec(Node *root)
    {
        if (root != NULL)
        {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }
    void insert(int val)
    {
        Root = buildtree(Root, val);
    }
    void inorder()
    {
        inorderRec(Root);
    }
    int level(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return max(level(root->left), level(root->right)) + 1;
        }
    }
    int buildlevel()
    {
        int max = level(Root);
        return max;
    }
    void *invertRec(Node *root)
    {
        if (root != NULL)
        {
            invertRec(root->left);
            invertRec(root->right);
            Node *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        // return root;
    }
    void mirror()
    {
        invertRec(Root);
    }
};
int main()
{
    Tree t;
    t.insert(7);
    t.insert(6);
    t.insert(1);
    t.insert(11);
    t.insert(3);
    t.insert(9);
    t.insert(4);
    t.inorder();
    // cout << "\n"<< "Level=" << t.buildlevel();
    t.mirror();
    cout << "\n";
    t.inorder();

    //     7
    //    / \
    //   6   11
    //  /    /
    // 1    9
    //  \
    //   3
    //    \
    //     4
}
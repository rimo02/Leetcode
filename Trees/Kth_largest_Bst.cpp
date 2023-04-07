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
    int klargest(int k)
    {
        return kinorder(Root, Root->data, k);
    }
    int kinorder(Node *root, int data, int k)
    {
        if (k < 1)
        {
            return data;
        }
        else
        {
            kinorder(root->left, root->data, k--);
            kinorder(root->right, root->data, k--);
        }
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
    cout << "\nEnter k: ";
    int k;
    cin >> k;
    cout << t.klargest(k);
}
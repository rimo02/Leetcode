//Construct a BST from Preorder

#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *right, *left;
};
struct Tree *constructTree(int *arr, int index, int len);
struct Tree *buildBST(int *arr, int len);
void Inorder(struct Tree *Ptr);
int main()
{
    int n ;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number:");
        scanf("%d", &arr[i]);
    }
    int index = 0;
    struct Tree *root = buildBST(arr,n);
    Inorder(root);
}
struct Tree *buildBST(int *arr, int len)
{
    int index = 0;
    return constructTree(arr, index, len-1);
}
struct Tree *constructTree(int *arr, int index, int len)
{
    if (index > len)
    {
        return NULL;
    }
    struct Tree *root = (struct Tree *)malloc(sizeof(struct Tree));
    root->data = arr[index];
    root->left=root->right=NULL;
    int i;
    for (i = index; i <= len; i++)
    {
        if (arr[i] > root->data)
        {
            break;
        }
    }
    root->left = constructTree(arr, index + 1, i - 1);
    root->right = constructTree(arr, i, len);
    return root;
}
void Inorder(struct Tree *Ptr)
{
    if (Ptr == NULL)
    {
        return;
    }
    Inorder(Ptr->left);
    printf("%d ", Ptr->data);
    Inorder(Ptr->right);
}

#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *RC, *LC;
};
void buildTree(struct Tree **Root, int item);
int Search(struct Tree *Root, int ele);
void Inorder(struct Tree *Ptr);
int main()
{
    struct Tree *Root = NULL;
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10, 13};
    for (int i = 0; i < 10; i++)
    {
        buildTree(&Root, arr[i]);
    }
    printf("\nInorder=");
    Inorder(Root);
    printf("\nEnter the element to be Searched:");
    int ele;
    scanf("%d", &ele);
    int f = Search(Root, ele);
    if (f == 1)
    {
        printf("Element found!!");
    }
    else
    {
        printf("Element not found!!");
    }
    free(Root);
}
void buildTree(struct Tree **Root, int item) // Creating a BST
{
    if (*Root == NULL)
    {
        *Root = (struct Tree *)malloc(sizeof(struct Tree));
        (*Root)->data = item;
        (*Root)->LC = (*Root)->RC = NULL;
    }
    else if (item <= (*Root)->data)
    {
        buildTree(&((*Root)->LC), item);
    }
    else
    {
        buildTree(&((*Root)->RC), item);
    }
}
void Inorder(struct Tree *Ptr)
{
    if (Ptr == NULL)
    {
        return;
    }
    Inorder(Ptr->LC);
    printf("%d ", Ptr->data);
    Inorder(Ptr->RC);
}
int Search(struct Tree *Root, int ele)
{
    if (Root != NULL)
    {
        if (Root->data == ele)
        {
            return 1;
        }
        else if (ele < Root->data)
        {
            Search(Root->LC, ele);
        }
        else
        {
            Search(Root->RC, ele);
        }
    }
    else
    {
        return 0;
    }
}
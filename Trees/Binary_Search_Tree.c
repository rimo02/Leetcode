#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *RC, *LC;
};
void buildTree(struct Tree **Root, int item);
void Inorder(struct Tree *Ptr);
void Preorder(struct Tree *Ptr);
void Postorder(struct Tree *Ptr);
int main()
{
    struct Tree *Root = NULL;
    int arr[10] = {7, 4, 12, 3, 6, 8, 1, 5, 10, 13};
    for (int i = 0; i < 10; i++)
    {
        buildTree(&Root, arr[i]);
    }
    printf("\nInorder=");
    Inorder(Root);
    printf("\nPreorder=");
    Preorder(Root);
    printf("\nPostorder=");
    Postorder(Root);
    free(Root);
}
void buildTree(struct Tree **Root, int item)
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
void Preorder(struct Tree *Ptr)
{
    if (Ptr == NULL)
    {
        return;
    }
    printf("%d ", Ptr->data);
    Preorder(Ptr->LC);
    Preorder(Ptr->RC);
}
void Postorder(struct Tree *Ptr)
{
    if (Ptr == NULL)
    {
        return;
    }
    Postorder(Ptr->LC);
    Postorder(Ptr->RC);
    printf("%d ", Ptr->data);
}

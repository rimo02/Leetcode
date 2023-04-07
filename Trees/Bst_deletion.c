#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *RC, *LC;
};
void buildTree(struct Tree **Root, int item);
int Search(struct Tree *Root, int key);
void Inorder(struct Tree *Ptr);
struct Tree *Deletion(struct Tree *Root, int key);
struct Tree *inorderSucessor(struct Tree *Root);
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
    printf("\nEnter the key element to be deleted:");
    int key;
    scanf("%d", &key);
    Root = Deletion(Root, key);
    printf("\nInorder after deletion=");
    Inorder(Root);
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
struct Tree *Deletion(struct Tree *Root, int key)
{
    if (Root == NULL)
    {
        return NULL;
    }
    if (key < Root->data)
    {
        Root->LC = Deletion(Root->LC, key);
    }
    else if (key > Root->data)
    {
        Root->RC = Deletion(Root->RC, key);
    }
    else
    {
        if (Root->LC == NULL && Root->RC == NULL)
        {
            return NULL;
        }
        else if (Root->LC == NULL)
        {
            struct Tree *Temp = Root->RC;
            free(Root);
            return Temp;
        }
        else if (Root->RC == NULL)
        {
            struct Tree *Temp = Root->LC;
            free(Root);
            return Temp;
        }
        else
        {
            struct Tree *Temp = inorderSucessor(Root->RC);
            Root->data = Temp->data;
            Root->RC = Deletion(Root->RC, Temp->data);
            return Root;
        }
    }
}
struct Tree *inorderSucessor(struct Tree *Root)
{
    struct Tree *temp = NULL;
    while (temp != NULL && temp->LC != NULL)
    {
        temp = temp->LC;
    }
    return temp;
}

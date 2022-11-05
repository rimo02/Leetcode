#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int data;
    struct Tree *RC, *LC;
};
void buildTree(struct Tree *Ptr);
void Inorder(struct Tree *Ptr);
void Preorder(struct Tree *Ptr);
void Postorder(struct Tree *Ptr);
int main()
{
    struct Tree *Root;
    Root = (struct Tree *)malloc(sizeof(struct Tree));
    buildTree(Root);
    printf("\nInorder=");
    Inorder(Root);
    printf("\nPreorder=");
    Preorder(Root);
    printf("\nPostorder=");
    Postorder(Root);
    free(Root);
}
void buildTree(struct Tree *Ptr)
{
    int ch;
    printf("Enter the value:");
    scanf("%d", &Ptr->data);
    Ptr->LC = NULL;
    Ptr->RC = NULL;
    printf("Do you want to add left child of %d (0/1)?", Ptr->data);
    scanf("%d", &ch);
    if (ch == 1)
    {
        struct Tree *New;
        New = (struct Tree *)malloc(sizeof(struct Tree));
        Ptr->LC = New;
        buildTree(New);
    }
    printf("Do you want to add right child of %d (0/1)?", Ptr->data);
    scanf("%d", &ch);
    if (ch == 1)
    {
        struct Tree *New;
        New = (struct Tree *)malloc(sizeof(struct Tree));
        Ptr->RC = New;
        buildTree(New);
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

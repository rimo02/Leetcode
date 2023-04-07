#include <stdio.h>
#include <stdlib.h>
struct Tree
{
    int Data;
    struct Tree *RC, *LC;
};
struct Stack
{
    struct Tree *t;
    struct Stack *Next;
};
void buildTree(struct Tree *Ptr);
void Inorder(struct Tree *Root);
void Preorder(struct Tree *Root);
void Postorder(struct Tree *Root);
int isEmpty(struct Stack *Top);
void Push(struct Tree *Ptr, struct Stack **Top);
struct Tree *Pop(struct Stack **Top);
int main()
{
    struct Tree *Root;
    Root = (struct Tree *)malloc(sizeof(struct Tree));
    buildTree(Root);
    // printf("\nInorder=");
    // Inorder(Root);
    printf("\nPreorder=");
    Preorder(Root);
    // printf("\nPostorder=");
    // Postorder(Root);
    free(Root);
}
void buildTree(struct Tree *Ptr)
{
    int ch;
    printf("Enter the value:");
    scanf("%d", &Ptr->Data);
    Ptr->LC = NULL;
    Ptr->RC = NULL;
    printf("Do you want to add left child of %d (0/1)?", Ptr->Data);
    scanf("%d", &ch);
    if (ch == 1)
    {
        struct Tree *New;
        New = (struct Tree *)malloc(sizeof(struct Tree));
        Ptr->LC = New;
        buildTree(New);
    }
    printf("Do you want to add right child of %d (0/1)?", Ptr->Data);
    scanf("%d", &ch);
    if (ch == 1)
    {
        struct Tree *New;
        New = (struct Tree *)malloc(sizeof(struct Tree));
        Ptr->RC = New;
        buildTree(New);
    }
}
void Push(struct Tree *Ptr, struct Stack **Top)
{
    struct Stack *New;
    New = (struct Stack *)malloc(sizeof(struct Stack));
    New->t = Ptr;
    New->Next = *Top;
    *Top = New;
}
struct Tree *Pop(struct Stack **Top)
{
    struct Tree *Prev;
    struct Stack *Temp;
    if (!isEmpty(*Top))
    {
        Temp = *Top;
        Prev = Temp->t;
        *Top = Temp->Next;
        free(Temp);
        return Prev;
    }
    else
    {
        exit(0);
    }
}
int isEmpty(struct Stack *Top)
{
    return (Top == NULL) ? 1 : 0;
}
void Inorder(struct Tree *Root)
{
    struct Stack *Top = NULL;
    struct Tree *Ptr = Root;
    while (1)
    {
        if (Ptr != NULL)
        {
            Push(Ptr, &Top);
            Ptr = Ptr->LC;
        }
        else
        {
            if (isEmpty(Top))
            {
                break;
            }
            Ptr = Pop(&Top);
            printf("%d ", Ptr->Data);
            Ptr = Ptr->RC;
        }
    }
}
void Preorder(struct Tree *Root)
{
    struct Stack *Top = NULL;
    struct Tree *Ptr = Root;
    while (1)
    {
        if (Ptr != NULL)
        {
            if (Ptr->RC != NULL)
            {
                Push(Ptr->RC, &Top);
            }
            printf("%d ", Ptr->Data);
            Ptr = Ptr->LC;
        }
        else
        {
            if (isEmpty(Top))
            {
                break;
            }
            Ptr = Pop(&Top);
        }
    }
}
void Postorder(struct Tree *Root)
{
    struct Stack *Top = NULL;
    struct Tree *Ptr = Root;
    struct Tree *ptr1 = NULL;
    struct Tree *ptr2 = NULL;
    struct Stack *stack;
    while (1)
    {
        if (Ptr != NULL)
        {
            if (Ptr->RC != NULL)
            {
                Push(Ptr->RC, &Top);
            }
            Push(Ptr, &Top);
            Ptr = Ptr->LC;
        }
        else
        {
            if (isEmpty(Top))
            {
                break;
            }
            ptr1 = Pop(&Top);
            if (ptr1->RC && Top->t == ptr1->RC)
            {
                ptr2 = Pop(&Top);
                Push(ptr1, &Top);
                Push(ptr2, &Top);
                Ptr = ptr1->RC;
            }
            else
            {
                printf("%d ", ptr1->Data);
                // Ptr = NULL;
            }
        }
    }
}
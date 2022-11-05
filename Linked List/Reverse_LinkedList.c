#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
struct Node *Reverse(struct Node *Head);
struct Node *Create(struct Node *Head);
void display(struct Node *Head);
int main()
{
    struct Node *Head = NULL;
    Head = Create(Head);
    printf("\nOriginal list:\n");
    display(Head);
    Head = Reverse(Head);
    printf("\nReversed list:\n");
    display(Head);
}
struct Node *Create(struct Node *Head)
{
    struct Node *New, *Ptr;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a number:");
    scanf("%d", &New->Data);
    New->Next = NULL;
    Head = New;
    Ptr = Head;
    char ch;
    printf("Do you want to continue(y/n):");
    scanf(" %c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        New = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter a number:");
        scanf("%d", &New->Data);
        New->Next = NULL;
        Ptr->Next = New;
        Ptr = Ptr->Next;
        printf("Do you want to continue(y/n):");
        scanf(" %c", &ch);
    }
    return Head;
}
struct Node *Reverse(struct Node *Head)
{
    if (Head == NULL)
    {
        return Head;
    }
    else
    {
        struct Node *Prev = NULL, *Current = Head, *Next = NULL;
        while (Current != NULL)
        {
            Next = Current->Next;
            Current->Next = Prev;
            Prev = Current;
            Current = Next;
        }
        Head = Prev;
        return Head;
    }
}
void display(struct Node *Head)
{
    struct Node *Ptr = Head;
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}
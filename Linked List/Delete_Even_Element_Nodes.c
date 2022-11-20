#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
struct Node *Create(struct Node *Head);
struct Node *DeleteEven(struct Node *Head);
void display(struct Node *Head);
int main()
{
    struct Node *Head;
    Head = Create(Head);
    printf("\nOriginal list:\n");
    display(Head);
    Head = DeleteEven(Head);
    if (Head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nDeleted list:\n");
        display(Head);
    }
}
struct Node *Create(struct Node *Head)
{
    struct Node *New, *Ptr, *index;
    Head = NULL;
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
struct Node *DeleteEven(struct Node *Head)
{
    struct Node *Ptr = Head, *prev = NULL, *Temp;
    while (1)
    {
        if (Ptr->Data % 2 == 0)
        {
            Temp = Head;
            Head = Head->Next;
            free(Temp);
            Ptr = Head;
        }
        else
        {
            break;
        }
    }
    while (Ptr != NULL)
    {
        if (Ptr->Data % 2 == 0)
        {
            Temp = Ptr;
            prev->Next = Ptr->Next;
            Ptr = Ptr->Next;
            free(Temp);
        }
        else
        {
            prev = Ptr;
            Ptr = Ptr->Next;
        }
    }
    if (Head == NULL)
    {
        return Head;
    }
    else
        return Head;
}
void display(struct Node *Head)
{
    struct Node *Ptr;
    Ptr = Head;
    if (Head == NULL)
    {
        printf("List is empty");
    }
    while (Ptr != NULL)
    {
        printf("Value of Node=%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}
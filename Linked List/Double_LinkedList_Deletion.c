// Deletion in double linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Prev;
};
int main()
{
    struct Node *Head, *New, *Ptr;
    Head = NULL;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a number:");
    scanf("%d", &New->Data);
    New->Next = NULL;
    New->Prev = NULL;
    Head = New;
    Ptr = New;
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
        New->Prev = Ptr;
        Ptr = New; // Always update ptr=New at end
        printf("Do you want to continue(y/n):");
        scanf(" %c", &ch);
    }
    Ptr = Head;
    printf("Before Deletion:\n");
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
    printf("Enter 1 for start,2 for any position,3 for end:");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        Ptr = Head;
        Head = (Head->Next);
        Head->Prev = NULL;
        free(Ptr);
    }
    else if (choice == 2)
    {
        int pos, count = 1;
        printf("Enter the position to be deleted:");
        scanf("%d", &pos);
        Ptr = Head;
        while (count < pos-1)
        {
            Ptr = Ptr->Next;
            count++;
        }
        struct Node *Temp;
        Temp = Ptr->Next;
        Ptr->Next=Temp->Next;
        Ptr = (Temp->Next)->Prev;
        free(Temp);
    }
    else if (choice == 3)
    {
        struct Node *Temp;
        Ptr = Head;
        while ((Ptr->Next)->Next != NULL)
        {
            Ptr = Ptr->Next;
        }
        Temp = (Ptr->Next);
        Ptr->Next = NULL;
        free(Temp);
    }
    else
    {
        printf("Wrong choice");
    }
    Ptr = Head;
    printf("After Deletion:\n");
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}
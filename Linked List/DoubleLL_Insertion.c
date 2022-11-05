// Insertion in double linked list
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
    printf("Before Insertion:\n");
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
        printf("Enter the number:");
        int data;
        scanf("%d", &data);
        Ptr = Head;
        New = (struct Node *)malloc(sizeof(struct Node));
        New->Data = data;
        New->Next = Ptr;
        New->Prev = NULL;
        Head = New;
    }
    else if (choice == 2)
    {
        int pos, data;
        New = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the number:");
        scanf("%d", &data);
        New->Data = data;
        printf("Enter the position to insert:");
        scanf("%d", &pos);
        int count = 1;
        Ptr = Head;
        while (count < pos - 1)
        {
            Ptr = Ptr->Next;
            count++;
        }
        New->Next = Ptr->Next;
        New->Prev = Ptr;
        Ptr->Next = New;
        printf("Node inserted succesfully\n");
    }
    else if (choice == 3)
    {
        printf("Enter the number:");
        int data;
        scanf("%d", &data);
        New = (struct Node *)malloc(sizeof(struct Node));
        New->Data = data;
        New->Next = NULL;
        Ptr = Head;
        while (Ptr->Next != NULL)
        {
            Ptr = Ptr->Next;
        }
        New->Prev = Ptr;
        Ptr->Next = New;
    }
    printf("After Insertion:\n");
    Ptr = Head;
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
int main()
{
    struct Node *Head, *New, *Ptr;
    Head = NULL;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a number:");
    scanf("%d", &New->Data);
    New->Next = NULL;
    Head = New; // Head is pointing to 1st node
    Ptr = Head; // Use this pointer to traverser to rest of LL
    char ch;
    printf("Do you want to continue(y/n):");
    scanf(" %c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        New = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter a number:");
        scanf("%d", &New->Data);
        New->Next = NULL;
        Ptr->Next = New; // Initially ptr was pointing to head. Now it is pointing to address of 1st node
        Ptr = Ptr->Next; // Update ptr
        printf("Do you want to continue(y/n):");
        scanf(" %c", &ch);
    }
    Ptr = Head;
    printf("Before Deletion\n");
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
    printf("Enter 1 for start, 2 for any position between start and end, and 3 for end:");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        if (Head == NULL)
        {
            printf("Deletion not possible");
        }
        else
        {
            struct Node *Temp;
            Temp = Head;
            Head = (Head->Next);
            free(Temp);
            printf("Node Deleted\n");
        }
    }
    else if (choice == 2)
    {
        int pos;
        printf("Enter the position to be deleted:");
        scanf("%d", &pos);
        Ptr = Head;
        int count = 1;
        while (count < pos - 1)
        {
            Ptr = Ptr->Next;
            count++;
        }
        struct Node *Temp;
        Temp = Ptr->Next;
        Ptr->Next = (Ptr->Next)->Next;
        free(Temp);
    }
    else if (choice == 3)
    {
        if (Head == NULL)
        {
            printf("No Node exist");
        }
        else
        {
            Ptr = Head;
            while ((Ptr->Next)->Next != NULL)
            {
                Ptr = Ptr->Next;
            }
            struct Node *Temp;
            Temp = Ptr->Next;
            printf("%d\n", Temp);
            Ptr->Next = NULL;
            free(Temp);
            printf("Node deleted\n");
        }
    }
    else
    {
        printf("Wrong choice:");
    }
    Ptr = Head;
    printf("After Deletion\n");
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}
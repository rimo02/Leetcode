#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
int main()
{
    struct Node *Head, *New, *Ptr, *index;
    Head = NULL;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter a number:");
    scanf("%d", &New->Data);
    New->Next = NULL;
    Head = New; // Head is pointing to 1st node
    Ptr = Head; // Use this pointer to traverse to rest of LL
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
    printf("\nUnsorted list:\n");
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
    Ptr = Head;
    int p;
    while (Ptr != NULL)
    {
        index = Ptr->Next;
        int temp;
        while (index != NULL)
        {
            if (index->Data < Ptr->Data)
            {
                temp = index->Data;
                index->Data = Ptr->Data;
                Ptr->Data = temp;
            }
            index = index->Next;
        }
        Ptr = Ptr->Next;
    }
    Ptr = Head;
    printf("\nSorted list:\n");
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}
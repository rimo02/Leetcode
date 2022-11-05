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
    printf("Final Circular Linked List\n");
    Ptr = Head;
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d and Address=%d\n", Ptr->Data, Ptr->Next);
        Ptr = Ptr->Next;
        if (Ptr->Next == NULL)
        {
            printf("Value of Node=:%d and Address=%d\n", Ptr->Data, Ptr->Next);
            Ptr->Next = Head;
            Ptr = Ptr->Next;
            break;
        }
    }
}

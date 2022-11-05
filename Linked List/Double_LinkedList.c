//Creating a double linked list
#include<stdio.h>
#include<stdlib.h>
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
    scanf("%d",&New->Data);
    New->Next=NULL;
    New->Prev=NULL;
    Head=New;
    Ptr=New;
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
        New->Prev=Ptr;
        Ptr = New;//Always update ptr=New at end
        printf("Do you want to continue(y/n):");
        scanf(" %c", &ch);
    }
    Ptr = Head;
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}

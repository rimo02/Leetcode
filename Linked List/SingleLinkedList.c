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
    Head = New;
    Ptr = Head;
    char ch;
    printf("Do you wan to continue(y/n):");
    scanf(" %c",&ch);
    while(ch=='Y'||ch=='y')
    {
        New = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter a number:");
        scanf("%d", &New->Data);
        New->Next=NULL;
        Ptr->Next=New;
        Ptr=Ptr->Next;
        printf("Do you wan to continue(y/n):");
        scanf(" %c",&ch);
    }
    Ptr=Head;
    while (Ptr!=NULL)
    {
        printf("Value of Node=:%d\n",Ptr->Data);
        Ptr=(Ptr->Next)->Next;
    }
}
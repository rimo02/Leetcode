#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
void insert_first(struct Node *Head, int data);
void insert_end(struct Node *Head, int data);
void insert_pos(struct Node *Head, int data, int pos);
void display(struct Node *Head);
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
    printf("Do you wan to continue(y/n):");
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
    printf("Before Insertion\n");
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
        insert_first(Head, data);
    }
    else if (choice == 2)
    {
        int pos, data;
        printf("Enter the number:");
        scanf("%d", &data);
        printf("Enter the position to insert:");
        scanf("%d", &pos);
        insert_pos(Head, data, pos);
    }
    else if (choice == 3)
    {
        printf("Enter the number:");
        int data;
        scanf("%d", &data);
        insert_end(Head, data);
    }
    else
    {
        printf("Wrong choice");
    }
    display(Head);
}
void insert_first(struct Node *Head, int data)
{
    struct Node *New;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->Data = data;
    New->Next = Head; // Ptr points to head which is initially pointing to first node address
    Head = New;
    printf("Node inserted succesfully\n");
}
void insert_end(struct Node *Head, int data)
{
    struct Node *New, *Ptr;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->Data=data;
    Ptr = Head;
    while (Ptr->Next != NULL)
    {
        Ptr = Ptr->Next;
    }
    Ptr->Next = New;
    New->Next = NULL;
    printf("Node inserted succesfully\n");
}
void insert_pos(struct Node *Head, int data, int pos)
{
    struct Node *New, *Ptr;
    New = (struct Node *)malloc(sizeof(struct Node));
    int count = 1;
    Ptr = Head;
    while (count < pos - 1)
    {
        Ptr = Ptr->Next;
        count++;
    }
    New->Data = data;
    New->Next = Ptr->Next;
    Ptr->Next = New;
    printf("Node inserted succesfully\n");
}
void display(struct Node *Head)
{
    struct Node *Ptr;
    Ptr = Head;
    printf("After Insertion\n");
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}
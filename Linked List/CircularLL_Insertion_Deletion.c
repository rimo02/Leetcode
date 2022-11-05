#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
void insert_beg(struct Node *Head, int num);
void insert_pos(struct Node *Head, int data, int pos);
void insert_end(struct Node *Head, int num);
void delete_beg(struct Node *Head);
void delete_pos(struct Node *Head, int pos);
void delete_end(struct Node *Head);
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
    while (Ptr != NULL) // Creating Circular Linked List
    {
        if (Ptr->Next == NULL)
        {
            Ptr->Next = Head;
            break;
        }
        Ptr = Ptr->Next;
    }
    display(Head);
    int choice;
    printf("Enter 1 for insertion,2 for deletion:");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter 1 for insertion at beginning, 2 for insertion at pos, 3 for insertion at end:");
        int c;
        scanf("%d", &c);
        if (c == 1)
        {
            printf("Enter the number:");
            int num;
            scanf("%d", &num);
            insert_beg(Head, num);
        }
        else if (c == 2)
        {
            int pos, data;
            printf("Enter the number:");
            scanf("%d", &data);
            printf("Enter the position to insert:");
            scanf("%d", &pos);
            insert_pos(Head, data, pos);
        }
        else if (c == 3)
        {
            printf("Enter the number:");
            int num;
            scanf("%d", &num);
            insert_end(Head, num);
        }
        else
        {
            printf("Wrong Choice!\n");
        }
    }
    else if (choice == 2)
    {
        printf("Enter 1 for deletion at beginning, 2 for deletion at pos, 3 for deletion at end:");
        int c;
        scanf("%d", &c);
        if (c == 1)
        {
            delete_beg(Head);
        }
        else if (c == 2)
        {
            int pos;
            printf("Enter the position to delete:");
            scanf("%d", &pos);
            delete_pos(Head, pos);
        }
        else if (c == 3)
        {
            delete_end(Head);
        }
        else
        {
            printf("Wrong Choice!");
        }
    }
}
void insert_beg(struct Node *Head, int num)
{
    struct Node *New, *Ptr = Head;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->Data = num;
    while ((Ptr->Next) != Head)
    {
        Ptr = Ptr->Next;
    }
    Ptr->Next = New;
    New->Next = Head;
    Head = New;
    display(Head);
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
    Ptr = New;
    printf("Node inserted succesfully\n");
}
void insert_end(struct Node *Head, int num)
{
    struct Node *New, *Ptr = Head;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->Data = num;
    while ((Ptr->Next) != Head)
    {
        Ptr = Ptr->Next;
    }
    New->Next = Head;
    Ptr->Next = New;
    New = Head;
    display(Head);
}
void delete_beg(struct Node *Head)
{
    struct Node *Ptr = Head, *Temp;
    while (Ptr->Next != Head)
    {
        Ptr = Ptr->Next;
    }
    Ptr->Next = Head->Next;
    Temp = Head;
    Head = Head->Next;
    free(Temp);
    display(Head);
}
void delete_pos(struct Node *Head, int pos)
{
    struct Node *Ptr, *Temp;
    Ptr = Head;
    int count = 1;
    while (count < pos - 1)
    {
        Ptr = Ptr->Next;
        count++;
    }
    Temp = Ptr->Next;
    Ptr->Next = (Ptr->Next)->Next;
    free(Temp);
    display(Head);
}
void delete_end(struct Node *Head)
{
    struct Node *Ptr = Head, *Temp;
    while ((Ptr->Next)->Next != Head)
    {
        Ptr = Ptr->Next;
    }
    Temp=(Ptr->Next);
    Ptr=Head;
    free(Temp);
    display(Head);
}
void display(struct Node *Head)
{
    struct Node *Ptr = Head;
    while (Ptr->Next != Head)
    {
        printf("Value of Node:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
    printf("Value of Node:%d\n", Ptr->Data);
}
// Creating a double linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Prev;
};
void insert_beg(struct Node *Head, int num);
void insert_pos(struct Node *Head, int pos, int num);
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
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
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
            int pos, Data;
            printf("Enter the number:");
            scanf("%d", &Data);
            printf("Enter the position to insert:");
            scanf("%d", &pos);
            insert_pos(Head, pos, Data);
        }
        else if (c == 3)
        {
            printf("Enter the number:");
            int num;
            scanf("%d", &num);
            insert_end(Head, num);
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
            int p;
            printf("Enter the position to delete:");
            scanf("%d", &p);
            delete_pos(Head, p);
        }
        else if (c == 3)
        {
            delete_end(Head);
        }
        else
        {
            printf("Wrong Choice\n");
        }
    }
    else
    {
        printf("Wrong choice:");
    }
}
void insert_beg(struct Node *Head, int num)
{
    struct Node *Ptr, *New;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->Data = num;
    New->Prev = NULL;
    Head->Prev = New;
    New->Next = Head;
    Head = New;
    printf("Node inserted Successfully\n");
    display(Head);
}
void insert_pos(struct Node *Head, int pos, int num)
{
    if (pos == 1)
    {
        insert_beg(Head, num);
    }
    else
    {
        struct Node *Ptr, *New;
        New = (struct Node *)malloc(sizeof(struct Node));
        New->Data = num;
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
        display(Head);
    }
}
void insert_end(struct Node *Head, int num)
{
    struct Node *New, *Ptr;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->Data = num;
    New->Next = NULL;
    Ptr = Head;
    while (Ptr->Next != NULL)
    {
        Ptr = Ptr->Next;
    }
    New->Prev = Ptr;
    Ptr->Next = New;
    display(Head);
}
void delete_beg(struct Node *Head)
{
    struct Node *Ptr;
    Ptr = Head;
    Head = (Head->Next);
    Head->Prev = NULL;
    free(Ptr);
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
    Ptr->Next = Temp->Next;
    Ptr = (Temp->Next)->Prev;
    free(Temp);
    display(Head);
}
void delete_end(struct Node *Head)
{
    struct Node *Temp, *Ptr;
    Ptr = Head;
    while ((Ptr->Next)->Next != NULL)
    {
        Ptr = Ptr->Next;
    }
    Temp = (Ptr->Next);
    Ptr->Next = NULL;
    free(Temp);
    display(Head);
}
void display(struct Node *Head)
{
    struct Node *Ptr = Head;
    while (Ptr != NULL)
    {
        printf("Value of Node=:%d\n", Ptr->Data);
        Ptr = Ptr->Next;
    }
}

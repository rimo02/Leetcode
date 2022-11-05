#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};
void Enqueue();
void Dequeue();
void Display();
void Peek();
struct Node *Front = NULL;
struct Node *Rear = NULL;
int main()
{
    char choice = 'y';
    int ch;
    while (choice == 'y' || choice == 'Y')
    {
        printf("\nEnter 1 for insertion, 2 for deletion, 3 to display, 4 to Peek:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            Peek(Front);
            break;
        // case 5:
        //     IsEmpty(Front, Rear);
        //     break;
        // case 6:
        //     IsFull(Front, Rear);
        //     break;
        default:
            printf("Wrong choice\n");
            break;
        }
        printf("\nDo you want to Continue?");
        scanf(" %c", &choice);
    }
}
void Enqueue()
{
    struct Node *New;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data:");
    int data;
    scanf("%d", &data);
    New->Data = data;
    New->Next = NULL;
    if (Front == NULL && Rear == NULL)
    {
        Front = New;
        Rear = New;
    }
    else
    {
        Rear->Next = New;
        Rear = New;
    }
}
void Dequeue()
{
    int val;
    struct Node *Temp;
    if (Front == NULL && Rear == NULL)
    {
        printf("Queue Underflow");
    }
    else if (Front == Rear)
    {
        val = Front->Data;
        printf("%d Deleted", val);
        Temp = Front;
        Front = NULL;
        Rear = NULL;
    }
    else
    {
        val = Front->Data;
        printf("%d Deleted", val);
        Temp = Front;
        Front = Front->Next;
    }
    free(Temp);
}
void Display()
{
    if (Front == NULL && Rear == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        struct Node *Ptr = Front;
        printf("Elements of Queue:");
        while (Ptr != Rear)
        {
            printf("%d ", Ptr->Data);
            Ptr = Ptr->Next;
        }
        printf("%d ",Ptr->Data);
    }
}
void Peek()
{
    if(Front==NULL && Rear==NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Element at front=%d",Front->Data);
    }
}

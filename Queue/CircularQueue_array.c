#include <stdio.h>
#include <stdlib.h>
void CQInsert(int *Que, int maxsize);
void CQDelete(int *Que, int maxsize);
void Display(int *Que, int maxsize);
int front = -1, rear = -1;
int main()
{
    int n;
    printf("Enter the length of array:");
    scanf("%d", &n);
    int *Que = malloc(n * sizeof(int));
    int maxsize = n - 1;
    char choice = 'y';
    int ch;
    while (choice == 'y' || choice == 'Y')
    {
        printf("\nEnter 1 for insertion, 2 for deletion, 3 to display, 4 to Peek:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            CQInsert(Que, maxsize);
            break;
        case 2:
            CQDelete(Que, maxsize);
            break;
        case 3:
            Display(Que, maxsize);
            break;
        // case 4:
        //     Peek(Que, maxsize);
        //     break;
        // case 5:
        //     IsEmpty(maxsize);
        //     break;
        // case 6:
        //     IsFull(maxsize);
        //     break;
        default:
            printf("Wrong choice\n");
            break;
        }
        printf("\nDo you want to Continue?");
        scanf(" %c", &choice);
    }
}
void CQInsert(int *Que, int maxsize)
{
    if (front == 0 && rear == maxsize || ((rear + 1) % (maxsize + 1) == front))
    {
        printf("Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        printf("Enter the number to insert:");
        scanf("%d", &Que[rear]);
    }
    else
    {
        rear = (rear + 1) % (maxsize + 1);
        printf("Enter the number to insert:");
        scanf("%d", &Que[rear]);
    }
}
void CQDelete(int *Que, int maxsize)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow");
    }
    else if (front == rear)
    {
        printf("%d Deleted", Que[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("%d Deleted", Que[front]);
        front = (front + 1) % (maxsize + 1);
    }
}
void Display(int *Que, int maxsize)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nELements of Queue:");
        for (int i = front; i != rear; i = (i + 1) % (maxsize + 1))
        {
            printf("%d ", Que[i]);
        }
        printf("%d ", Que[rear]);
    }
}
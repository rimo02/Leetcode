#include <stdio.h>
#include <stdlib.h>
void Enqueue(int *Queue, int maxsize);
void Dequeue(int *Queue);
void Display(int *Queue, int maxsize);
void Peek(int *Queue);
void IsEmpty(int *Queue);
void IsFull(int maxsize);
int front = -1, rear = -1;
int main()
{
    int n;
    printf("Enter the length of array:");
    scanf("%d", &n);
    int *Queue = malloc(n * sizeof(int));
    int maxsize = 9;
    char choice = 'y';
    int ch;
    while (choice == 'y' || choice == 'Y')
    {
        printf("\nEnter 1 for insertion, 2 for deletion, 3 to display, 4 to Peek:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Enqueue(Queue, maxsize);
            break;
        case 2:
            Dequeue(Queue);
            break;
        case 3:
            Display(Queue, maxsize);
            break;
        case 4:
            Peek(Queue);
            break;
        case 5:
            IsEmpty(Queue);
            break;
        case 6:
            IsFull(maxsize);
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
        printf("\nDo you want to Continue?");
        scanf(" %c", &choice);
    }
}
void Enqueue(int *Queue, int maxsize)
{
    if (rear == maxsize)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        printf("Enter the number to insert in the queue:");
        int num;
        scanf("%d", &num);
        rear = rear + 1;
        Queue[rear] = num;
    }
}
void Dequeue(int *Queue)
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue Underflow");
    }
    else if (front == rear)
    {
        val = Queue[front];
        front = -1;
        rear = -1;
        printf("\nDeleted : %d", val);
    }
    else
    {
        val = Queue[front];
        front++;
        printf("\nDeleted : %d", val);
    }
}
void Display(int *Queue, int maxsize)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("\nElements of queue:");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", Queue[i]);
        }
    }
}
void Peek(int *Queue)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d", Queue[front]);
    }
}
void IsEmpty(int *Queue)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}
void IsFull(int maxsize)
{
    if (rear == maxsize || front + 1 == rear)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Queue is not Full\n");
    }
}
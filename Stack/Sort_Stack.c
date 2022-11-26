#include <stdio.h>
#include <stdlib.h>
void insert(int *stack, int ele, int maxsize);
void push(int *stack, int maxsize, int ele);
int pop(int *stack);
void display(int *stack, int top);
int top = -1;
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int *stack = (int *)malloc(n * sizeof(int));
    int maxsize = n - 1;
    printf("Enter 1 to insert,2 to display:");
    int choice;
    int ele;
    scanf("%d", &choice);
    while (choice == 1 || choice == 2)
    {
        switch (choice)
        {
        case 1:
            printf("Enter element to insert:");
            scanf("%d", &ele);
            insert(stack, ele, maxsize);
            break;
        case 2:
            display(stack, top);
            break;
        default:
            printf("Wrong Choice");
            break;
        }
        printf("Enter 1 to insert,2 to display:");
        scanf("%d", &choice);
    }
}
void insert(int *stack, int ele, int maxsize)
{
    if (top == -1 || stack[top] < ele)
    {
        push(stack, maxsize, ele);
        return;
    }
    else if (stack[top] == ele)
    {
        return;
    }
    else
    {
        int x = pop(stack);
        insert(stack, ele, maxsize);
        push(stack, maxsize, x);
    }
}
void push(int *stack, int maxsize, int ele)
{
    if (top == maxsize)
    {
        return;
    }
    else
    {
        stack[++top] = ele;
    }
}
int pop(int *stack)
{
    if (top == -1)
    {
        printf("Deletion not possible\n");
    }
    else
    {
        int x;
        x = stack[top];
        top--;
        return x;
    }
}
void display(int *stack, int top)
{
    if (top == -1)
    {
        return;
    }
    else
    {
        printf("%d\n", stack[top]);
        return display(stack, top - 1);
    }
}
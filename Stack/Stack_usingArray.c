#include <stdio.h>
#include <stdlib.h>
int push(int *stack, int top, int maxsize);
int pop(int *stack, int top, int maxsize);
void display(int *stack, int top);
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;
    ;
    int maxsize = n - 1;
    printf("Enter 1 for pushing,2 for popping,3 to display:");
    int choice;
    scanf("%d", &choice);
    while (choice == 1 || choice == 2 || choice == 3)
    {
        switch (choice)
        {
        case 1:
            top = push(stack, top, maxsize);
            break;
        case 2:
            top = pop(stack, top, maxsize);
            break;
        case 3:
            display(stack, top);
            break;
        default:
            printf("Wrong Choice");
            break;
        }
        printf("Enter 1 for pushing,2 for popping,3 to display:");
        scanf("%d", &choice);
    }
}
int push(int *stack, int top, int maxsize)
{
    if (top == maxsize)
    {
        printf("Insertion not possible\n");
    }
    else
    {
        printf("Enter a number:");
        scanf("%d", &stack[++top]);
    }
    return top;
}
int pop(int *stack, int top, int maxsize)
{
    if (top == -1)
    {
        printf("Deletion not possible:\n");
    }
    else
    {
        printf("Element %d deleted\n", stack[top--]);
    }
    return top;
}
void display(int *stack, int top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("%d\n", stack[top]);
        return display(stack, top - 1);
    }
}
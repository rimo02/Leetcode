#include <stdio.h>
#include <stdlib.h>
int maxsize;
void push(int *stack, int ele, int *top);
void pop(int *stack, int *top);
void display(int *stack, int top);
void delMid(int *stack, int *top);
int main()
{
    int n;
    scanf("%d", &n);
    int stack[n];
    maxsize = n - 1;
    int top = -1;
    printf("Enter 1 for pushing,2 for popping,3 to display,4 to delete Middle element of stack:");
    int choice;
    scanf("%d", &choice);
    while (choice == 1 || choice == 2 || choice == 3 || choice == 4)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the number to push:");
            int num;
            scanf("%d", &num);
            push(stack, num, &top);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            delMid(stack, &top);
            break;
        }
        printf("Enter 1 for pushing, 2 for popping, 3 to display, 4 to delete Middle element of stack:");
        scanf("%d", &choice);
    }
}
void push(int *stack, int ele, int *top)
{
    if (*top == maxsize)
    {
        printf("\nInsertion not possible");
    }
    else
    {
        *top = *top + 1;
        stack[*top] = ele;
    }
}
void pop(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("\nDeletion not possible");
    }
    printf("%d Deleted\n", stack[*top]);
    *top = *top - 1;
}
void display(int *stack, int top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
void delMid(int *stack, int *top)
{
    int newtop = -1;
    int newStack[maxsize];
    int count = 0;
    int s = *top / 2;
    while (count < s)
    {
        push(newStack, stack[*top], &newtop);
        count++;
        *top = *top - 1;
    }
    pop(stack, top);
    while (newtop >= 0)
    {
        push(stack, newStack[newtop], top);
        newtop--;
    }
}
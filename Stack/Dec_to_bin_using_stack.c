#include <stdio.h>
#define MAX 100
int push(int *stack, int top, int p);
int pop(int *top, int *stack);
int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);
    int top = -1;
    int n = num;
    int stack[MAX];
    while (n != 0)
    {
        top = push(stack, top, n % 2);
        n = n / 2;
    }
    printf("The binary equivalent= ");
    while (top != -1)
    {
        printf("%d", pop(&top, stack));
    }
}
int push(int *stack, int top, int p)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top] = p;
    }
    return top;
}
int pop(int *top, int *stack)
{
    int x;
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = stack[*top];
        *top = *top - 1;
    }
    return x;
}
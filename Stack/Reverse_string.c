#include <stdio.h>
#include <string.h>
#define MAX 100
int push(char *stack, int top, char ch);
char pop(int *top, char *stack);
int main()
{
    char str[40];
    printf("Enter the string:");
    gets(str);
    int top = -1;
    char stack[MAX];
    int i = 0;
    while (str[i] != '\0')
    {
        top = push(stack, top, str[i]);
        i++;
    }
    printf("The reversed string=");
    while (top != -1)
    {
        printf("%c", pop(&top, stack));
    }
}
int push(char *stack, int top, char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top] = ch;
    }
    return top;
}
char pop(int *top, char *stack)
{
    char x;
    if (*top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = stack[*top];
        *top=*top-1;
    }
    return x;
}
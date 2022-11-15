#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *push(struct Node *Top);
struct Node *pop(struct Node *Top);
void display(struct Node *Top);
int main()
{
    struct Node *Top = NULL;
    int ch = 1;
    printf("Enter 1 for pushing,2 for popping,3 to display :");
    scanf("%d", &ch);
    while (ch == 1 || ch == 2 || ch == 3)
    {
        if (ch == 1)
        {
            Top = push(Top);
        }
        else if (ch == 2)
        {
            Top = pop(Top);
        }
        else if (ch == 3)
        {
            display(Top);
        }
        else
        {
            printf("\nWrong Choice!!\n");
            break;
        }
        printf("Enter 1 for pushing,2 for popping,3 to display :");
        scanf("%d", &ch);
    }
}
struct Node *push(struct Node *Top)
{
    struct Node *New;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number:");
    scanf("%d", &New->data);
    New->next = Top;
    Top = New;
    return Top;
}
struct Node *pop(struct Node *Top)
{
    if (Top == NULL)
    {
        printf("Popping not possible!\n");
    }
    else
    {
        struct Node *Ptr = Top, *Temp;
        Temp = Top->next;
        Top = Temp;
        free(Ptr);
        printf("Node deleted\n");
    }
    return Top;
}
void display(struct Node *Top)
{
    struct Node *Ptr = Top;
    if (Top == NULL)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("\nThe stack is:\n");
        while (Ptr != NULL)
        {
            printf("%d\n", Ptr->data);
            Ptr = Ptr->next;
        }
    }
}

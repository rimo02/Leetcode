// Polynomial Addition using Linked list
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *Next;
};
struct Node *Create(struct Node *Head);
struct Node *insert(struct Node *Head, int co, int ex);
void display(struct Node *Head);
int main()
{
    struct Node *Head1, *Head2, *Head3;
    printf("Enter details of first polynomial\n");
    Head1 = Create(Head1);
    printf("Enter details of second polynomial\n");
    Head2 = Create(Head2);
    printf("Coefficient\tExponent\n");
    display(Head1);
    printf("Coefficient\tExponent\n");
    display(Head2);
    struct Node *Ptr1 = Head1, *Ptr2 = Head2;
    while (Ptr1 != NULL && Ptr2 != NULL)
    {
        if (Ptr1->exp == Ptr2->exp)
        {
            Head3 = insert(Head3, Ptr1->coeff + Ptr2->coeff, Ptr1->exp);
            Ptr1 = Ptr1->Next;
            Ptr2 = Ptr2->Next;
        }
        else if (Ptr1->exp < Ptr2->exp)
        {
            Head3 = insert(Head3, Ptr1->coeff, Ptr1->exp);
            Ptr1 = Ptr1->Next;
        }
        else
        {
            Head3 = insert(Head3, Ptr2->coeff, Ptr2->exp);
            Ptr2 = Ptr2->Next;
        }
    }
    while (Ptr1 != NULL)
    {
        Head3 = insert(Head3, Ptr1->coeff, Ptr1->exp);
        Ptr1 = Ptr1->Next;
    }
    while (Ptr2 != NULL)
    {
        Head3 = insert(Head3, Ptr2->coeff, Ptr2->exp);
        Ptr2 = Ptr2->Next;
    }
    printf("Coefficient\tExponent\n");
    display(Head3);
}
struct Node *Create(struct Node *Head)
{
    struct Node *New, *Ptr;
    Head = NULL;
    New = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the coeffiecient:");
    scanf("%d", &New->coeff);
    printf("Enter the exponent:");
    scanf("%d", &New->exp);
    New->Next = NULL;
    Head = New;
    Ptr = Head;
    char ch;
    printf("Do you want to continue(y/n):");
    scanf(" %c", &ch);
    while (ch == 'Y' || ch == 'y')
    {
        New = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the coeffiecient:");
        scanf("%d", &New->coeff);
        printf("Enter the exponent:");
        scanf("%d", &New->exp);
        New->Next = NULL;
        Ptr->Next = New;
        Ptr = Ptr->Next;
        printf("Do you want to continue(y/n):");
        scanf(" %c", &ch);
    }
    return Head;
}
struct Node *insert(struct Node *Head, int co, int ex)
{
    struct Node *New, *Ptr;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->coeff = co;
    New->exp = ex;
    New->Next = NULL;
    if (Head == NULL)
    {
        Head = New;
    }
    else
    {
        Ptr = Head;
        while (Ptr->Next != NULL)
        {
            Ptr = Ptr->Next;
        }
        Ptr->Next = New;
    }
    printf("Node created!\n");
    return Head;
}
void display(struct Node *Head)
{
    struct Node *Ptr = Head;
    while (Ptr != NULL)
    {
        printf("%d\t\t%d\n", Ptr->coeff, Ptr->exp);
        Ptr = Ptr->Next;
    }
}
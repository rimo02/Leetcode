#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int row;
    int col;
    int value;
    struct Node *Next;
};
struct Node *create(struct Node *Head, int i, int j, int val);
struct Node *sparse(struct Node *Head1, struct Node *Head2, struct Node *Head3);
void display(struct Node *Head);
int main()
{
    struct Node *Head1 = NULL, *Head2 = NULL, *Head3 = NULL;
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int **arr1 = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr1[i] = (int *)malloc(n * sizeof(int));
    }
    int **arr2 = (int **)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr2[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter elements of 1st array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the number:");
            scanf("%d", &arr1[i][j]);
            if (arr1[i][j] != 0)
            {
                Head1 = create(Head1, i, j, arr1[i][j]);
            }
        }
    }
    printf("Enter elements of 2nd array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the number:");
            scanf("%d", &arr2[i][j]);
            if (arr2[i][j] != 0)
            {
                Head2 = create(Head2, i, j, arr2[i][j]);
            }
        }
    }
    printf("Triplet Representation of sparse matrix\n");
    display(Head1);
    display(Head2);
    Head3 = sparse(Head1, Head2, Head3);
    display(Head3);
}
struct Node *create(struct Node *Head, int i, int j, int val)
{
    struct Node *New, *Ptr;
    New = (struct Node *)malloc(sizeof(struct Node));
    New->row = i;
    New->col = j;
    New->value = val;
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
    return Head;
}
struct Node *sparse(struct Node *Head1, struct Node *Head2, struct Node *Head3)
{
    struct Node *Ptr1 = Head1, *Ptr2 = Head2, *Ptr3 = Head3;
    while (Ptr1 != NULL && Ptr2 != NULL)
    {
        if (Ptr1->row < Ptr2->row)
        {
            Ptr3->row = Ptr1->row;
            Ptr3->col = Ptr1->col;
            Ptr3->value = Ptr1->value;
            Ptr3 = Ptr3->Next;
            Ptr1 = Ptr1->Next;
        }
        else if (Ptr2->row < Ptr1->row)
        {
            Ptr3->row = Ptr2->row;
            Ptr3->col = Ptr2->col;
            Ptr3->value = Ptr2->value;
            Ptr3 = Ptr3->Next;
            Ptr2 = Ptr2->Next;
        }
        // This means row is equal. Compare columns
        else if (Ptr1->col < Ptr2->col)
        {
            Ptr3->row = Ptr1->row;
            Ptr3->col = Ptr1->col;
            Ptr3->value = Ptr1->value;
            Ptr3 = Ptr3->Next;
            Ptr1 = Ptr1->Next;
        }
        else if (Ptr2->col < Ptr1->col)
        {
            Ptr3->row = Ptr2->row;
            Ptr3->col = Ptr2->col;
            Ptr3->value = Ptr2->value;
            Ptr3 = Ptr3->Next;
            Ptr2 = Ptr2->Next;
        }
        else
        {
            Ptr3->row = Ptr2->row;
            Ptr3->col = Ptr2->col;
            Ptr3->value = Ptr2->value + Ptr1->value;
            Ptr3 = Ptr3->Next;
            Ptr1 = Ptr1->Next;
            Ptr2 = Ptr2->Next;
        }
        while (Ptr1 != NULL)
        {
            Ptr3->row = Ptr1->row;
            Ptr3->col = Ptr1->col;
            Ptr3->value = Ptr1->value;
            Ptr3 = Ptr3->Next;
            Ptr1 = Ptr1->Next;
        }
        while (Ptr2 != NULL)
        {
            Ptr3->row = Ptr2->row;
            Ptr3->col = Ptr2->col;
            Ptr3->value = Ptr2->value;
            Ptr3 = Ptr3->Next;
            Ptr2 = Ptr2->Next;
        }
        return Head3;
    }
}
void display(struct Node *Head)
{
    if (Head == NULL)
    {
        printf("NO Node exits");
    }
    else
    {
        struct Node *Ptr = Head;
        printf("Row\tColumn\tValue\n");
        while (Ptr != NULL)
        {
            printf("%d\t%d\t%d\n", Ptr->row, Ptr->col, Ptr->value);
            Ptr = Ptr->Next;
        }
    }
}
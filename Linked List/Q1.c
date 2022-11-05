#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Link;
};
int main()
{
    struct Node N1, N2, N3;
    struct Node *Head;
    Head = &N1;
    printf("Enter the number:");
    scanf("%d", &N1.Data);
    N1.Link = &N2;
    printf("Enter the number:");
    scanf("%d", &N2.Data);
    N2.Link = &N3;
    printf("Enter the number:");
    scanf("%d", &N3.Data);
    N3.Link = NULL;
    struct Node *Ptr;
    Ptr = Head;
    while (Ptr != NULL)
    {
        printf("Value of Node:%d\n", Ptr->Data);
        Ptr = Ptr->Link;
    }
}
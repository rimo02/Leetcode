#include <stdio.h>
void buildTree(int t[], int index, int value);
int main()
{
    int t[20], index = 0, value;
    for (int i = 0; i < 20; i++)
    {
        t[i] = -1;
    }
    printf("Enter the root node:");
    scanf("%d", &value);
    char ch = 'y';
    buildTree(t, index, value);
    // printTree(t);
    for (int i = 0; i < 20; i++)
    {
        if (t[i] == -1)
        {
            printf("-");
        }
        else
        {
            printf("%d ", t[i]);
        }
    }
}
void buildTree(int t[], int index, int value)
{
    t[index] = value;
    int ch, data;
    printf("Do you want to add left child of %d (0/1)?", value);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter the left child:");
        scanf("%d", &data);
        buildTree(t, 2 * index + 1, data);
    }
    printf("Do you want to add right child of %d (0/1)?", value);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter the right child:");
        scanf("%d", &data);
        buildTree(t, 2 * index + 2, data);
    }
}
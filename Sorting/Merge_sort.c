#include <stdio.h>
void merge(int *arr, int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1], arr2[n2];
    // Copying into two arrays from l to mid and from mid+1 to r
    for (i = 0; i < n1; i++)
    {
        arr1[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }
    i = 0, j = 0, k = l;
    // merging of two sorted arrays
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr[k++] = arr2[j++];
    }
}
void mergeSort(int *arr, int l, int r, int n)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid, n);
        mergeSort(arr, mid + 1, r, n);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number :");
        scanf("%d", &arr[i]);
    }
    printf("\nArray elements before sorting:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    int l = 0, r = n;
    mergeSort(arr, l, r, n);
    printf("\nArray elements after sorting:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
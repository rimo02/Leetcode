#include <iostream>
using namespace std;
int main()
{
    int arr[] = {2, -6, 7, -4, 5, -2, 1, -11, -5, 8};
    int n = 10;
    int left = 0, right = n - 1;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    while (left <= right)
    {
        if (arr[left] < 0 && arr[right] > 0)
        {
            left++;
        }
        else if (arr[left] > 0 && arr[right] < 0)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        else if (arr[left] > 0 && arr[right] > 0)
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
}
#include <iostream>
using namespace std;
int main()
{
    int arr[] = {2, -6, 7, -4, 5, -2, 7, -11, -5, 8};
    int n = 10;
    int left = 0, right = n - 1;
    int first, last;
    int ele = 2;
    while (left <= right)
    {
        if (arr[left] != ele)
        {
            left++;
        }
        else if (arr[right] != ele)
        {
            right--;
        }
        else
        {
            first = left;
            last = right;
            break;
        }
    }
    cout << first << " " << last;
}
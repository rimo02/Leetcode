// Three way of partitiong an array around a given range
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a number:";
        cin >> arr[i];
    }
    cout << "Enter the minimum and maximum range:";
    int min, max;
    cin >> min >> max;
    int left = 0, right = n - 1;
    cout << "Before: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // for (int i = 0; i <= right; i++)
    // {
    //     if (arr[i] < left)
    //     {
    //         if (i == left)
    //         {
    //             left++;
    //             i--;
    //             for (int j = 0; j < n; j++)
    //             {
    //                 cout << arr[j] << " ";
    //             }
    //             cout << endl;
    //         }
    //         else
    //         {
    //             swap(&arr[i], &arr[left]);
    //             left++;
    //             for (int j = 0; j < n; j++)
    //             {
    //                 cout << arr[j] << " ";
    //             }
    //             cout << endl;
    //         }
    //     }
    //     else if (arr[i] > right)
    //     {
    //         swap(&arr[i], &arr[right]);
    //         right--;
    //         i--;
    //         for (int j = 0; j < n; j++)
    //         {
    //             cout << arr[j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    for (int i = 0; i <= right;)
    {
        // If current element is smaller than
        // range, put it on next available smaller
        // position.
        if (arr[i] < min)
        {
            // if i and start are same in that case we can't
            // swap swap only if i is greater than start
            if (i == left)
            {
                left++;
                i++;
                for (int j = 0; j < n; j++)
                {
                    cout << arr[j] << " ";
                }
                cout << i << " " << left << " " << right;
                cout << endl;
            }
            else
                swap(arr[i++], arr[left++]);
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << i << " " << left << " " << right;
            cout << endl;
        }

        // If current element is greater than
        // range, put it on next available greater
        // position.
        else if (arr[i] > max)
        {
            swap(arr[i], arr[right--]);
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << i << " " << left << " " << right;
            cout << endl;
        }
        else
        {
            i++;
            for (int j = 0; j < n; j++)
            {
                cout << arr[j] << " ";
            }
            cout << i << " " << left << " " << right;
            cout << endl;
        }
    }

    cout << "\n"
         << "After: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

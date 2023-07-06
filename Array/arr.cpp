// #include <iostream>
// using namespace std;

// int main()
// {
//     int arr[] = {1, 2, 3, 8, 5, 6, 7, 4, 9};
//     int first = -1, second = -1;
//     for (int i = 0; i < 10; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             if (first == -1)
//             {
//                 first = arr[i];
//                 // second = arr[i + 1];
//             }
//             else if(second == -1)
//             {
//                 second = arr[i + 1];
//             }
//         }
//     }
//     cout << first << endl;
//     cout << second << endl;
// }
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 8, 5, 6, 7, 4, 9};
    int prev = -20000;
    int first = -1, second = -1;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < prev) // since increasing order
        {
            if (first == -1)
            {
                first = prev;
            }
            // else if (second == -1)
            second = arr[i];
        }
        prev = arr[i];
    }
    cout << first << endl;
    cout << second << endl;
}
#include <iostream>
#include <algorithm>
using namespace std;
int rob(int arr[], int n)
{
    if (n < 0)
    {
        return 0;
    }
    return max(rob(arr, n - 1), arr[n] + rob(arr, n - 2));
}
int main()
{
    int arr[] = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165};
    cout << rob(arr, 24);
}
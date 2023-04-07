#include <iostream>
using namespace std;
int main()
{
    int arr[] = {2, -6, 7, -4, 5, -2, 1, -11, -5, 8};
    int n = 10;
    int max_sum = INT64_MIN;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if (curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    cout << "Maximum subarray:" << max_sum;
}
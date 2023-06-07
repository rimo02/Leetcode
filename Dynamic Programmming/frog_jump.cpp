#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
// int jump(int arr[], int n)
// {
//     int left, right;
//     if (n == 0)
//     {
//         return 0;
//     }
//     left = jump(arr, n - 1) + abs(arr[n] - arr[n - 1]); 
//     if (n > 1)
//     {
//         right = jump(arr, n - 2) + abs(arr[n] - arr[n - 2]);
//     }
//     return min(left, right);
// }
int jump(int arr[],int n)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int jump2=INT16_MAX;
        int jump1=dp[i-1]+abs(arr[i]-arr[i-1]);
        if(i>1)
        {
            jump2=dp[i-2]+abs(arr[i]-arr[i-2]);
        }
        dp[i]=min(jump1,jump2);
    }
    return dp[n-1];
}

int main()
{
    int arr[] = {30, 10, 60, 10, 60, 50};
    int n = 6;
    cout << jump(arr, n);
}
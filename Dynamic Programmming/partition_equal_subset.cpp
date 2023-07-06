#include <iostream>
#include <vector>
using namespace std;

int recursion(int arr[], int n, int target, int sum)
{
    if (target == sum / 2)
        return true;
    if (n == 0)
        return false;
    if (arr[n - 1] > sum)
        return recursion(arr, n - 1, arr[n - 1], sum);
    return recursion(arr, n - 1, sum - arr[n - 1], sum) || recursion(arr, n - 1, arr[n - 1], sum);
}
int memoization()
{
    
}
int main()
{
    int arr[] = {1, 2, 3, 5, 1};
    int n = 5;
    int sum = 12;
    int target = 6;
    if (recursion(arr, n, target, sum))
    {
        cout << "The array can be partitioned" << endl;
    }
    else
    {
        cout << "the array can't be partitoned" << endl;
    }
}
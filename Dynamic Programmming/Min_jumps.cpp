// Given an array arr[] where each element represents the max number of steps that can be made forward from that index. The task is to find the minimum number of jumps to reach the end of the array starting from index 0. If the end isn’t reachable, return -1.
// Examples: 

// Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3 (1-> 3 -> 9 -> 9)
// Explanation: Jump from 1st element to 2nd element as there is only 1 step.
// Now there are three options 5, 8 or 9. I
// f 8 or 9 is chosen then the end node 9 can be reached. So 3 jumps are made.

// Input:  arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// Output: 10
// Explanation: In every step a jump is needed so the count of jumps is 10.

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int minJumps(int arr[], int curr, int end)
{
    if (curr > end)
    {
        return 0;
    }
    int temp = INT16_MAX;
    for (int k = 1; k <= arr[curr]; k++)
    {
        temp = min(temp, 1 + minJumps(arr, curr + k, end));
    }
    return temp;
}
int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr, 0, n - 1));
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ans = 0;
    void merge(vector<int> &arr, int l, int mid, int r)
    {
        int size = (r - l + 1);
        int j = mid + 1;
        for (int i = l; i <= mid; i++)
        {
            int count = 0;
            while (j <= r && arr[i] > 2 * arr[j])
            {
                count++;
                j++;
            }
            ans += count;
        }
        vector<int> temp(size, 0);
        int i = l;
        j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid)
        {
            temp[k++] = arr[i++];
        }
        while (j <= r)
        {
            temp[k++] = arr[j++];
        }
        int m = 0;
        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[m++];
        }
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
    int reversePairs(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};
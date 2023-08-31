#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int Partition(vector<int> &arr, int lb, int ub)
    {
        if (lb == ub)
            return lb;
        int pivot = arr[lb];
        int start = lb;
        int end = ub;
        while (start < end)
        {
            while (arr[start] <= pivot)
            {
                start++;
            }
            while (arr[end] > pivot)
            {
                end--;
            }
            if (start < end)
            {
                swap(arr[start], arr[end]);
            }
        }
        swap(arr[lb], arr[end]);
        return end;
    }
    int kthLargest(vector<int> &arr, int k)
    {
        int n = arr.size();
        k = n - k;
        int lb = 0, ub = arr.size() - 1;
        while (1)
        {
            int idx = Partition(arr, lb, ub);
            if (idx == k)
            {
                // ele = arr[idx];
                // break;
                return arr[idx];
            }
            else if (idx < k)
            {
                lb = idx + 1;
            }
            else
            {
                ub = idx - 1;
            }
        }
        return -1;
    }
    int findKthLargest(vector<int> &arr, int k)
    {
        return kthLargest(arr, k);
    }
    int kthSmallest(vector<int> &arr, int k)
    {
        int ele;
        int lb = 0, ub = arr.size() - 1;
        while (1)
        {
            int idx = Partition(arr, lb, ub);
            if (idx == k - 1)
            {
                ele = arr[idx];
                break;
            }
            if (idx < k - 1)
            {
                lb = idx + 1;
            }
            else
            {
                ub = idx - 1;
            }
        }
        return ele;
    }
};
int main()
{
    vector<int> arr = {2, 1};
    Solution S;
    cout << S.findKthLargest(arr, 2);
}

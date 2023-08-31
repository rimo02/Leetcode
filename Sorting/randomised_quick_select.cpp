#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class Solution
{
public:
    int Partition(vector<int> &arr, int lb, int ub)
    {
        int pivot = arr[ub], i = lb, j = lb;
        while (j < ub)
        {
            if (arr[j] < pivot)
            {
                swap(arr[i], arr[j]);
                i++;
            }
            j++;
        }
        swap(arr[i], arr[ub]);
        return i;
    }

    int RandomPartition(vector<int> &arr, int lb, int ub)
    {
        int n = ub - lb + 1;
        int pivotidx = rand() % n;    // choose a random index
        swap(arr[pivotidx], arr[ub]); // make the random element as pivot from end
        return Partition(arr, lb, ub);
    }
    int median(vector<int> &arr, int mid, int lb, int ub)
    {
        if (lb <= ub)
        {
            int idx = Partition(arr, lb, ub);
            if (idx == mid) // odd indexed array
            {
                return arr[mid];
            }
            else if (idx < mid)
            {
                return median(arr, mid, idx + 1, ub);
            }
            else
            {
                return median(arr, mid, lb, idx - 1);
            }
        }
    }
};
int main()
{
    vector<int> arr = {2, 1, 5, 3, 7, 9, 20, 11};
 // vector<int> arr = {1, 2, 3, 5, 7, 9, 11, 20};
    Solution S;
    int n = arr.size();
    cout << "Median = " << S.median(arr, n / 2, 0, n - 1);
}
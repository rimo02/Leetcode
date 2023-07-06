#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            return (target == nums[0]) ? 0 : -1;
        }

        int low = 0, high = nums.size() - 1, pivot = 0;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        pivot = low;
        cout << pivot << endl;
        high = nums.size() - 1;
        low = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int realMid = (mid + pivot) % nums.size();
            if (target == nums[realMid])
                return realMid;
            if (nums[realMid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    // vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    // vector<int> nums = {1};
    // vector<int> nums = {5, 1, 3};
    vector<int> nums = {4, 5, 1, 3};
    Solution S;
    // S.search(nums, 0);
    cout << "Index= " << S.search(nums, 2);
}
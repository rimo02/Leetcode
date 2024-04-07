#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int mergeAndSort(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nums3;
        for (auto ele : nums1)
            nums3.push_back(ele);
        for (auto ele : nums2)
            nums3.push_back(ele);
        sort(nums3.begin(), nums3.end()); // TC = (n+m)*log(n+m)
        int s = nums3.size();
        if (s % 2 == 0)
        {
            return (nums3[s / 2] + nums3[s / 2 - 1]) / 2;
        }
        else
        {
            return nums3[s / 2];
        }
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1; // assuming n1 size < n2 size
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = (n1 + n2 + 1) / 2 - mid1;

            int max1 = (mid1 == 0) ? INT16_MIN : nums1[mid1 - 1];
            int min1 = (mid1 == n1) ? INT16_MAX : nums1[mid1];

            int max2 = (mid2 == 0) ? INT16_MIN : nums2[mid2 - 1];
            int min2 = (mid2 == n2) ? INT16_MAX : nums2[mid2];

            if (max1 <= min2 && max2 <= min1)
            {
                if ((n1 + n2) % 2 == 0)
                {
                    return (max(min1, min2) + min(max1, max2)) / 2;
                }
                else
                {
                    return max(max1, max2);
                }
            }
            else if (max2 > min1)
            {
                low = mid1 + 1;
            }
            else
            {
                high = mid1 - 1;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution S;
    cout << S.findMedianSortedArrays(nums1, nums2);
}

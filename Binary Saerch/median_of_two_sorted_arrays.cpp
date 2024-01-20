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
    }
};

#include <bits/stdc++.h>
using namespace std;
class NumArray
{
private:
    vector<int> segment;
    int n;

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        segment.resize(2 * n);
        for (int i = 0; i < n; i++)
        {
            segment[n + i] = nums[i]; // leaf nodes
        }
        for (int i = n - 1; i >= 0; i--)
        {
            segment[i] = segment[2 * i] + segment[2 * i + 1];
        }
    }

    void update(int index, int val)
    {
        index += n;
        segment[index] = val;
        index = index / 2;
        while (index > 1)
        {
            segment[index] = segment[2 * index] + segment[2 * index + 1];
            index /= 2;
        }
    }

    int sumRange(int left, int right)
    {
        left += n;
        right += n;
        int sum = 0;
        while (left <= right)
        {
            if (left % 2 == 1) // if left is a right child (since indexing goes 2i and 2i + 1)
            {
                sum += segment[left++];
            }
            if (right % 2 == 0)
            {
                sum += segment[right--];
            }
            left = left >> 1;
            right = right >> 1;
        }
        return sum;
    }
};
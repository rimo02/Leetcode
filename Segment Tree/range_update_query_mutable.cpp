#include <bits/stdc++.h>
using namespace std;
// Segment tree with lazy propagation
class NumArray
{
private:
    vector<int> segment;
    int n;

    void build(int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            segment[idx] = arr[low];
            return;
        }
        int mid = (high + low) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        segment[idx] = segment[2 * idx + 1] + segment[2 * idx + 2];
    }

    void make(int idx, int low, int high, int pos, int val)
    {
        if (low == high)
        {
            segment[idx] = val;
            return;
        }
        int mid = (high + low) / 2;
        if (pos <= mid)
            make(2 * idx + 1, low, mid, pos, val);
        else
            make(2 * idx + 2, mid + 1, high, pos, val);
        segment[idx] = segment[2 * idx + 1] + segment[2 * idx + 2];
        return;
    }

    int solve(int idx, int low, int high, int l, int r)
    {
        if (l > high || r < low)
            return 0;
        // This checks if the entire segment range [low, high] is within the
        // query range [l, r].
        if (l <= low && r >= high)
            return segment[idx];
        int mid = (high + low) / 2;
        return solve(2 * idx + 1, low, mid, l, r) +
               solve(2 * idx + 2, mid + 1, high, l, r);
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        segment.resize(4 * n, 0);
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) { make(0, 0, n - 1, index, val); }

    int sumRange(int left, int right)
    {
        return solve(0, 0, n - 1, left, right);
    }
};

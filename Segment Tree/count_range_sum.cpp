#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
private:
    vector<int> segment;
    int n;

    void build(int idx, int low, int high, const vector<int> &arr)
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

    void update(int idx, int low, int high, int pos, int value)
    {
        if (low == high)
        {
            segment[idx] += value;
            return;
        }
        int mid = (high + low) / 2;
        if (pos <= mid)
        {
            update(2 * idx + 1, low, mid, pos, value);
        }
        else
        {
            update(2 * idx + 2, mid + 1, high, pos, value);
        }
        segment[idx] = segment[2 * idx + 1] + segment[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (r < low || l > high)
        {
            return 0;
        }
        if (l <= low && r >= high)
        {
            return segment[idx];
        }
        int mid = (high + low) / 2;
        return query(2 * idx + 1, low, mid, l, r) +
               query(2 * idx + 2, mid + 1, high, l, r);
    }

public:
    SegmentTree(int size)
    {
        n = size;
        segment.resize(4 * n, 0);
    }

    void update(int pos, int value) { update(0, 0, n - 1, pos, value); }

    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        set<long long> allSums(prefixSums.begin(), prefixSums.end());
        unordered_map<long long, int> index;
        int idx = 0;
        for (long long sum : allSums)
        {
            index[sum] = idx++;
        }

        SegmentTree tree(idx);
        int count = 0;

        for (long long sum : prefixSums)
        {
            auto left = allSums.lower_bound(sum - upper);
            auto right = allSums.upper_bound(sum - lower);
            for (auto it = left; it != right; ++it)
            {
                count += tree.query(index[*it], index[*it]);
            }
            tree.update(index[sum], 1);
        }

        return count;
    }
};
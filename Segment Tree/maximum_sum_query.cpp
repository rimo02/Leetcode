#include <bits/stdc++.h>
using namespace std;

vector<int> segment;
vector<int> arr;

void build(int idx, int low, int high)
{
    if (low == high)
    {
        segment[idx] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    segment[idx] = max(segment[2 * idx + 1], segment[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
        return segment[idx];
    if (high < l || low > r)
        return INT32_MIN;
    int mid = low + (high - low) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return max(left, right);
}

int main()
{
    int n;
    cin >> n;
    arr.resize(n);
    segment.resize(4 * n, 0); // Resize segment tree array to a suitable size

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(0, 0, n - 1);
    cout << "Segment tree build" << endl;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << query(0, 0, n - 1, l, r) << endl;
    }
}

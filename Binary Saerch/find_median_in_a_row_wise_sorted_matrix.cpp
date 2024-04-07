#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }
        int required = (R * C + 1) / 2;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int pos = 0;
            // count the number of elements <= mid . In each row use upper bound which indicates the number of elements below it
            for (int i = 0; i < R; i++)
            {
                pos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (pos < required)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5},
                                  {2, 6, 9},
                                  {3, 6, 9}};
    Solution S;
    cout << S.median(matrix, 3, 3);
}
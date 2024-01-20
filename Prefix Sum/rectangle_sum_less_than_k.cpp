#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT16_MIN;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = i; j < n; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    temp[k] += matrix[k][j];
                }
                set<int> st = {0};
                int sum = 0;
                for (auto it : temp)
                {
                    sum += it;
                    if (st.lower_bound(sum - k) != st.end())
                    {
                        res = max(res, sum - *st.lower_bound(sum - k)); //
                    }
                    st.insert(sum);
                }
            }
        }
        return res;
    }
};
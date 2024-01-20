#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int bruteForce(vector<vector<int>> M)
    {
        // code here
        int m = M.size();
        int n = M[0].size();
        int res = INT16_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int x = i; x < m; x++)
                {
                    for (int y = j; y < n; y++)
                    {
                        int sum = 0;
                        for (int a = i; a <= x; a++)
                        {
                            for (int b = j; b <= y; b++)
                            {
                                sum += M[a][b];
                            }
                        }
                        res = max(res, sum);
                    }
                }
            }
        }
        return res;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M)
    {
        // code here
        int maxSum = INT16_MIN;
        for (int i = 0; i < C; i++)
        {
            vector<int> temp(R, 0);
            for (int j = i; j < C; j++)
            {
                for (int k = 0; k < R; k++)
                {
                    temp[k] += M[k][j];
                }

                // apply kadanes algo in this temp
                int curr = 0, maxSubarraySum = INT16_MIN;
                for (int k = 0; k < R; k++)
                {
                    curr = max(temp[k], curr + temp[k]);
                    maxSubarraySum = max(maxSubarraySum, curr);
                }
                maxSum = max(maxSum, maxSubarraySum);
            }
        }
        return maxSum;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> left(nums.begin(), nums.begin() + n / 2),
            right(nums.begin() + n / 2, nums.end());
        vector<vector<int>> leftSums(left.size() + 1);
        vector<vector<int>> rightSums(right.size() + 1);
        for (int i = 0; i < (1 << left.size()); i++)
        {
            int sum = 0, idx = 0;
            for (int j = 0; j < left.size(); j++)
            {
                if (i & (1 << j))
                {
                    idx++;
                    sum += left[j];
                }
            }
            leftSums[idx].push_back(sum);
        }
        for (int i = 0; i < (1 << right.size()); i++)
        {
            int sum = 0, idx = 0;
            for (int j = 0; j < right.size(); j++)
            {
                if (i & (1 << j))
                {
                    idx++;
                    sum += right[j];
                }
            }
            rightSums[idx].push_back(sum);
        }
        for (auto &v : rightSums)
            sort(v.begin(), v.end());
        for (int i = 0; i < leftSums.size(); i++)
        {
            for (int j = 0; j < rightSums.size(); j++)
            {
                int x = i + j;
                if ((x != 0) && (x < n))
                {
                    for (auto &a : leftSums[i])
                    {
                        int num = (sum * x - a * n);
                        cout << sum * x << " " << a * n << endl;
                        if (num % n)
                            continue;
                        int b = num / n;
                        auto &v = rightSums[j];
                        auto itr = lower_bound(v.begin(), v.end(), b);
                        if (itr != v.end() && *itr == b)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution S;
    int x = S.splitArraySameAverage(nums);
}
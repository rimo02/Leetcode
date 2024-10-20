#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> generatesubset(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> res;
        for (int i = 0; i < (1 << n); i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    sum += arr[j];
                }
            }
            res.push_back(sum);
        }
        return res;
    }

    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        if (n == 1)
            return min(abs(goal), abs(nums[0] - goal));

        vector<int> startarray(nums.begin(), nums.begin() + n / 2);
        vector<int> endarray(nums.begin() + n / 2, nums.end());

        vector<int> firstHalf = generatesubset(startarray);
        vector<int> secondHalf = generatesubset(endarray);

        sort(secondHalf.begin(), secondHalf.end());

        int res = INT_MAX;
        for (int i = 0; i < firstHalf.size(); ++i)
        {
            int lb = lower_bound(secondHalf.begin(), secondHalf.end(), goal - firstHalf[i]) - secondHalf.begin();

            if (lb > 0)
                res = min(res, abs(goal - secondHalf[lb - 1] - firstHalf[i]));
            if (lb < secondHalf.size())
                res = min(res, abs(goal - secondHalf[lb] - firstHalf[i]));
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {5, -7, 3, 5};
    Solution S;
    int ans = S.minAbsDifference(nums, 6);
    cout << ans << endl;
    return 0;
}

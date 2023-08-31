#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void backtracking(vector<int> &candidates, int target, int j)
    {
        if (target == 0)
        {
            ans.push_back(sub);
            return;
        }
        if (target < 0)
            return;
        for (int i = j; i < candidates.size(); i++)
        {
            sub.push_back(candidates[i]);
            for (int k = 0; k < sub.size(); k++)
            {
                cout << sub[k] << " ";
            }
            cout << endl;
            backtracking(candidates, target - candidates[i], i+1);
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates, target, 0);
        return ans;
    }
};
int main()
{
    Solution S;
    vector<int> arr={2,3,5};
    S.combinationSum(arr,8);
}
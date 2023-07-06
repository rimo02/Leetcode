#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> res;
    string sub;
    void solve(string digits, vector<string> str, int index)
    {
        if (index >= digits.size())
        {
            res.push_back(sub);
            return;
        }
        int num = (int)(digits[index] - '0');
        string val = str[num];
        for (int i = 0; i < val.length(); i++)
        {
            sub.push_back(val[i]);
            solve(digits, str, index + 1);
            sub.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return res;
        vector<string> str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, str, 0);
        return res;
    }
};
int main()
{
    Solution S;
    vector<string> ans = S.letterCombinations("12");
    for (auto str : ans)
    {
        cout << str << " ";
    }
}
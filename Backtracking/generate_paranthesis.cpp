#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> vec;
    string str;
    void generate(int n, int open, int close)
    {
        if (str.size() == n * 2)
        {
            vec.push_back(str);
            return;
        }
        if (open < n)
        {
            str += "(";
            generate(n, open + 1, close);
            str.pop_back();
        }
        if (close < open)
        {
            str += ")";
            generate(n, open, close + 1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        // vector<string> str;
        generate(n, 0, 0);
        return vec;
    }
};
int main()
{
    Solution s;
    vector<string> arr = s.generateParenthesis(5);
    for (const string &str : arr)
    {
        cout << str << endl;
    }
}
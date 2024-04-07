#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string s, int k)
    {
        if (s.size() <= k)
            return "0";
        if (k == 0)
            return s;
        stack<char> stk;
        stk.push(s[0]);
        for (int i = 1; i < s.size(); i++)
        {
            while (!stk.empty() && stk.top() > s[i] && k > 0)
            {
                stk.pop();
                k--;
            }
            stk.push(s[i]);
            if (stk.size() == 1 && s[i] == '0')
            {
                stk.pop();
            }
        }
        while (k && !stk.empty())
        {
            k--;
            stk.pop();
        }

        string ans = "";
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.size() == 0 ? "0" : ans;
    }
};

int main()
{
    string s = "10200";
    int k = 1;
    Solution S;
    cout << S.removeKdigits(s, k);
    return 0;
}

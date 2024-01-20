#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> ans;
    void dfs(string s, int i, int dots, string ip)
    {
        if (dots == 4 && i == s.size())
        {
            ans.push_back(ip.substr(0, ip.size() - 1));
            return;
        }
        if (dots > 4)
            return;
        for (int j = i; j < min(i + 3, (int)s.size()); j++)
        {
            string str = s.substr(i, j - i + 1);
            if (stoi(str) <= 255 && (i == j || str[0] != '0'))
            {
                dfs(s, j + 1, dots + 1, ip + str + ".");
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        dfs(s, 0, 0, "");
        return ans;
    }
};
int main()
{
    string s = "25525511135";
    Solution S;
    vector<string> ans = S.restoreIpAddresses(s);
    for (auto str : ans)
        cout << str << " ";
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool palindrome(int i, int j, string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int tabulation(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            string temp = "";
            int minCost = INT16_MAX;
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (palindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(cost, minCost);
                }
                dp[i] = minCost;
            }
        }
        for (int i = 0; i < n + 1; i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
        return dp[0] - 1;
    }
    int minCut(string s)
    {
        // return recursion(0, s.size(), s)-1;
        return tabulation(s);
    }
};
int main()
{
    Solution S;
    string s = "ababbabuabba";
    cout << S.minCut(s);
}
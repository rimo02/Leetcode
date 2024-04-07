#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        stack<pair<char, int>> stk;
        int mx = 1;
        for (int i = 0; i < n; i++)
        {
            if (!stk.empty() && stk.top().first == s[i])
            {
                stk.push({s[i], stk.top().second + 1});
            }
            else
            {
                stk.push({s[i], 1});
            }
            mx = max(mx, stk.top().second);
        }
        cout << mx << " ";
        for (int i = 0; i < q; i++)
        {
            if (!stk.empty() && stk.top().first == s[i + n])
            {
                stk.push({s[i + n], stk.top().second + 1});
            }
            else
            {
                stk.push({s[i + n], 1});
            }
            mx = max(mx, stk.top().second);
            cout << mx << " ";
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> idx;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
            {
                idx.push_back(i);
            }
        }
        int ans = 1e9;
        for (auto i : idx)
        {
            int ca = 0, cc = 0;
            for (int j = 0; j < i; j++)
            {
                if (s[j] == 'a')
                    ca++;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == 'c')
                    cc++;
            }
            ans = min(ans,ca+ cc);
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        // use line-sweep
        // acculumate the shift from start and end of each index
        int n = s.size();
        vector<int> vec(n + 1, 0);
        for (auto &it : shifts)
        {
            if (it[2] == 1)
            {
                vec[it[0]] += 1;
                vec[it[1] + 1] -= 1;
            }
            else
            {
                vec[it[0]] -= 1;
                vec[it[1] + 1] += 1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            vec[i] += vec[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            int val = ((s[i] - 'a') + vec[i]) % 26;
            if (val < 0)
                val += 26;
            s[i] = 'a' + val;
        }
        return s;
    }
};
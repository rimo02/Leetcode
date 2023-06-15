#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int greedy(string s)
    {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[s[j]]++;
                if (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
                {
                    count++;
                }
            }
        }
        return count;
    }
    int slidingWindow(string s)
    {
        int n = s.length();
        unordered_map<char, int> map;
        int start = 0, end = 0;
        int count = 0;
        while (end < n)
        {
            map[s[end]]++;
            while (map['a'] >= 1 && map['b'] >= 1 && map['c'] >= 1)
            {
                count += (n - end);
                map[s[start]]--;
                start++;
            }
            end++;
        }
        return count;
    }
};
int main()
{
    Solution S;
    string s = "abcabbcacbabcababbacbbaacabcab";
    // string s="";
    cout << S.greedy(s) << endl;
    cout << S.slidingWindow(s);
}
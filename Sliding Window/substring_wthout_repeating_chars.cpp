#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "aceabecbed";
    // string s = "ab";
    int n = s.length();

    int left = 0, right = 0;
    int max_length = 0;
    unordered_map<char, int> mp;
    while (right < n)
    {
        char ch = s[right];
        auto iter = mp.find(ch);
        if (iter != mp.end()) // map already contains the element
        {
            left = max(left, mp[ch] + 1); // most_imp
            // left = mp[ch] + 1;
        }
        cout << left << " "
             << " mp[" << ch << "]=" << mp[ch] + 1 << " " << max_length << " " << (right - left+1) << endl;
        max_length = max(max_length, right - left+1);
        mp[ch] = right++;
    }
    cout << "\nMax substring length = " << max_length;
}
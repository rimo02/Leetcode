// 424. Longest Repeating Character Replacement
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achive this answer too.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int getfreq(unordered_map<char, int> &mp)
    {
        int maxfreq = 0;
        for (const auto &item : mp)
        {
            maxfreq = max(maxfreq, item.second);
        }
        return maxfreq;
    }
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int res = -1;
        while (j < s.size())
        {
            mp[s[j]]++;
            if (j - i + 1 - getfreq(mp) > k)
            {
                mp[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
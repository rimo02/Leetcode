// find the length of the longest subarray containing two disntinct characters such that the difference between the two distict ones is 1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> arr)
{
    unordered_map<int, int> mp;
    int left = 0, right = 0;
    int maxl = 0;
    while (right < arr.size())
    {
        int ele = arr[right];
        mp[ele]++;
        // window contraction
        while (mp.size() > 2 || abs(max_element(mp.begin(), mp.end())->first - min_element(mp.begin(), mp.end())->first) > 1) // most important
        {
            int ele = arr[left];
            mp[ele]--;
            if (mp[ele] == 0)
            {
                mp.erase(ele);
            }
            left++;
        }
        maxl = max(maxl, right - left + 1);
        right++;
    }
    return maxl;
}
int main()
{
    // vector<int> arr = {1, 1, 2, 3, 1, 1, 2, 2, 2, 2};
    vector<int> arr = {1, 0, 2, 0, 2, 3};
    cout << longestSubarray(arr);
}
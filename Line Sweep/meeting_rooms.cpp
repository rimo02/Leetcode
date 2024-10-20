#include <bits/stdc++.h>
using namespace std;
// Question - Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
// For example, Given[[ 0, 30 ], [ 5, 10 ], [ 15, 20 ]], return 2.
// Same as above just we have to keep track of maximum count of rooms and return it.
// When a meeting start we plot +1 for end we do -1.
// Now we scan the line, and store the value in count , if count is 1 that mean 1 meeting start, if its 2 that means 2nd meeting started before 1st ended, so we need 2 room atleast. This count we save in ans if count > ans .

class Solution
{
public:
    int minMeetingRooms(vector<pair<int, int>> &intervals)
    {
        // sweeping an imaginary line
        map<int, int> mp;
        for (auto &it : intervals)
        {
            mp[it.first] += 1;
            mp[it.second] -= 1;
        }
        int ans = 0;
        int count = 0;
        for (auto &it : mp)
        {
            count += it.second;
            ans = max(ans, count);
        }
        return ans;
    }
};
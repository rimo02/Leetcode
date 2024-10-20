#include <bits/stdc++.h>
using namespace std;
class MyCalendarTwo
{
public:
    map<int, int> mp;
    MyCalendarTwo() {}

    bool book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int count = 0;
        for (auto &it : mp)
        {
            count += it.second;
            if (count >= 3)
            {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};
/*
Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...](si< ei), find the minimum number of conference rooms required.

Example 1:
Input:
[[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input:
 [[7,10],[2,4]]

Output: 1
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> intervals = {
        {1, 18},
        {18, 23},
        {15, 29},
        {4, 15},
        {2, 11},
        {5, 13}};
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (!pq.empty() && intervals[i][0] >= pq.top())
        {
            pq.pop();
        }
        pq.push(intervals[i][1]);
    }
    cout << "No of rooms needed = " << pq.size() << endl;
}

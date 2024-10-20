#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> ans;
        multiset<int> pq{0};
        vector<pair<int, int>> points;
        for (auto &b : buildings)
        {
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }
        int ongoingHeight = 0;
        sort(points.begin(), points.end());
        for (int i = 0; i < points.size(); i++)
        {
            int cuur_point = points[i].first;
            int height = points[i].second;
            if (height < 0)
            {
                pq.insert(-height);
            }
            else
            {
                pq.erase(pq.find(height));
            }
            auto it = *pq.rbegin();
            if (ongoingHeight != it)
            {
                ongoingHeight = it;
                ans.push_back({cuur_point, ongoingHeight});
            }
        }
        return ans;
    }
};
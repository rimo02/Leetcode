#include <bits/stdc++.h>
using namespace std;
class Solutio
{
    vector<int> solve(vector<int> &A, vector<int> &B, int C)
    {
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        priority_queue<pair<int, pair<int, int>>> pq; // {sum,idx};
        pq.push({A[0] + B[0], {0, 0}});
        vector<int> ans;
        int m = A.size();
        int n = B.size();
        set<pair<int, int>> st;
        st.insert({0, 0});
        while (!pq.empty() && C--)
        {
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            ans.push_back(sum);
            if (i + 1 < m && st.find({i + 1, j}) == st.end())
            {
                pq.push({A[i + 1] + B[j], {i + 1, j}});
                st.insert({i + 1, j});
            }
            if (j + 1 < n && st.find({i, j + 1}) == st.end())
            {
                pq.push({A[i] + B[j + 1], {i, j + 1}});
                st.insert({i, j + 1});
            }
        }
        return ans;
    }
};

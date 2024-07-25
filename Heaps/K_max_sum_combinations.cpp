#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    priority_queue<pair<int, pair<int, int>>> pq; // {sum,idx};
    pq.push({A[0] + B[0], {0, 0}});
    vector<int> ans;
    int m = A.size();
    int n = B.size();
    while (!pq.empty() && C--)
    {
        int sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        cout << sum << " " << i << " " << j << endl;
        pq.pop();
        ans.push_back(sum);
        if (i + 1 < m)
        {
            pq.push({A[i + 1] + B[j], {i + 1, j}});
        }
        if (j + 1 < n)
        {
            pq.push({A[i] + B[j + 1], {i, j + 1}});
        }
    }
    return ans;
}
int main()
{
    vector<int> A = {4, 3, 2, 1};
    vector<int> B = {4, 3, 2, 1};
    vector<int> ans = solve(A, B, 8);
}
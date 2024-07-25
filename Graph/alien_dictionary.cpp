#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> toposort(vector<int> adj[], int n)
    {
        int indegree[n] = {0};
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node])
            {
                if (--indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return ans;
    }
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        vector<int> ans = toposort(adj, K);

        string res = "";
        for (auto it : ans)
            res += char(it + 'a');
        return res;
    }
};
int main()
{
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    Solution S;
    cout << S.findOrder(dict, N, K);
}
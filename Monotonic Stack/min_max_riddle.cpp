#include <bits/stdc++.h>
using namespace std;
int solve(vector<long> &arr, int k)
{
    deque<long> dq;
    int n = arr.size();
    long ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && i - k >= dq.front())
            dq.pop_front();
        while (!dq.empty() && arr[i] <= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (i + 1 >= k)
            ans = max(ans, arr[dq.front()]);
    }
    return ans;
}
void previousLess(vector<long> &arr, vector<long> &prev)
{
    int n = arr.size();
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] < arr[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            prev[i] = stk.top();
        }
        stk.push(i);
    }
}
void nextLess(vector<long> &arr, vector<long> &next)
{
    int n = arr.size();
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])
        {
            if (!stk.empty())
                next[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
}
vector<long> riddle(vector<long> arr)
{
    // BRUTE FORCE WONT WORK O(n2)
    //  vector<long> ans;
    //  for (int i = 1; i <= arr.size(); i++)
    //  {
    //      ans.push_back(solve(arr, i));
    //  }
    //  return ans;

    int n = arr.size();
    vector<long> previous(n + 1, -1);
    vector<long> next(n + 1, n);
    vector<vector<long>> window(n + 1);
    previousLess(arr, previous);
    nextLess(arr, next);
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &ui : arr)
        cin >> ui;
}
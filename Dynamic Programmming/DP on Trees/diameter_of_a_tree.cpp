#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<ll>;
using vc = vector<char>;
using vvi = vector<vector<ll>>;
using vvc = vector<vector<char>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using mii = map<ll, ll>;
using vii = vector<pair<ll, ll>>;
#define int long long int
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (1ll * (a / gcd(a, b)) * b)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define ceildiv(a, b) ((a + b - 1) / b)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define re return
const int MOD = 1e9 + 7;
const int MAX = 2e15;
#define inp(arr)         \
    for (auto &it : arr) \
        cin >> it;
#define disp(arr)        \
    for (auto &it : arr) \
        cout << it << " ";

// Longest path starts from node x and goes into its subtree(denoted by blue lines in the image). Lets define by dp1 this path length.
// Longest path starts in subtree of x, passes through x and ends in subtree of x(denoted by red line in image). Lets define by dp2 this path length.
void dfs(vi adj[], int parent, int node, vi &dp1, vi &dp2, int &diameter)
{
    vi fvalues;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        dfs(adj, node, it, dp1, dp2, diameter);
        fvalues.push_back(dp1[it]);
    }
    // we have the longest path starting from node i
    sort(all(fvalues));
    dp1[node] = 1;
    if (fvalues.size() > 0)
        dp1[node] += fvalues.back();
    if (fvalues.size() >= 2)
    {
        dp2[node] = (1 + fvalues.back() + fvalues[fvalues.size() - 2]);
    }
    diameter = max(diameter, max(dp1[node], dp2[node]));
}
void solve()
{
    int n;
    cin >> n;
    vi adj[n + 1];
    f(i, 0, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int diamater = 0;
    vi dp1(n + 1, 0), dp2(n + 1, 0);
    dfs(adj, -1, 1, dp1, dp2, diamater);
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

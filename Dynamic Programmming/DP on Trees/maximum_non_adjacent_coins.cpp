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
void dfs(vi adj[], int parent, int node, vi &dp1, vi &dp2, vi &coins)
{
    int sum1 = 0, sum2 = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        dfs(adj, node, it, dp1, dp2, coins);
        sum1 += dp2[it]; // taking the grandchildren
        sum2 += max(dp1[it], dp2[it]);
    }
    dp1[node] = sum1 + coins[node];
    dp2[node] = sum2;
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
    vi coins(n + 1);
    f(i, 1, n + 1)
    {
        cin >> coins[i];
    }
    vi dp1(n + 1, 0), dp2(n + 1, 0);
    dfs(adj, -1, 1, dp1, dp2, coins);
    cout << max(dp1[1], dp2[1]) << endl;
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

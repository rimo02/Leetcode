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

signed main()
{
    int n;
    cin >> n;
    vi arr(n);
    inp(arr);
    vi dp;
    f(i, 0, n)
    {
        if (dp.empty() || dp.back() < arr[i])
        {
            dp.push_back(arr[i]);
        }
        else
        {
            int idx = lower_bound(all(dp), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    }
    cout << dp.size();
}

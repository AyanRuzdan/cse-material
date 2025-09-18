```cpp
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define lb cout << endl;
ll solve(vector<ll> &v, ll idx, ll s1, ll s2, ll n)
{
    if (idx == n)
    {
        return abs(s1 - s2);
    }
    return min(solve(v, idx + 1, s1 + v[idx], s2, n), solve(v, idx + 1, s1, s2 + v[idx], n));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    cout << solve(v, 0, 0, 0, n);
    return 0;
}
```
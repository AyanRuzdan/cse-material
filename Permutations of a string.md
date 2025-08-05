```cpp
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define lb cout << endl;
void solve(size_t index, set<string> &res, string &s)
{
    if (index == s.size())
    {
        res.insert(s);
        return;
    }
    for (size_t i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        solve(index + 1, res, s);
        swap(s[index], s[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    set<string> res;
    solve(0, res, s);
    // sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto item : res)
        cout << item << "\n";
    return 0;
}
```

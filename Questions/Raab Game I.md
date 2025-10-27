```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define lb cout << endl;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        auto qc = " \n";
        cin >> n >> a >> b;
        if (a == 0 && b == 0)
        {
            cout << "YES\n";
            for (int i = 0; i < 2; i++)
                for (int j = 1; j <= n; j++)
                    cout << j << qc[j == n];
            continue;
        }
        if (a + b > n || !a || !b)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << i << qc[i == n];
        vector<int> v(n + 1);
        int ties = n - a - b;
        for (int i = 1; i <= a + b; i++)
        {
            int pos = (i + b - 1) % (a + b) + 1;
            v[pos] = i;
        }
        for (int i = a + b + 1; i <= n; i++)
            v[i] = i;
        for (int i = 1; i <= n; i++)
            cout << v[i] << qc[i == n];
    }
}

```
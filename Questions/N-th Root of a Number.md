```cpp
string find_pow(int mid, int n, int m)
{
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return "over";
    }
    if (ans == m)
        return "equal";
    return "under";
}
int find_root(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        string res = find_pow(mid, n, m);
        if (res == "equal")
            return mid;
        else if (res == "under")
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
```

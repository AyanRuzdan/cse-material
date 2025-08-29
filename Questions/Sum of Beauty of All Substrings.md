## Brute Force
Extra space and extra time
```cpp
int beautySum(string s)
{
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        map<char, int> mp;
        for (int j = i; j < n; j++)
        {
            mp[s[j]]++;
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for (auto item : mp)
            {
                maxi = max(maxi, item.second);
                mini = min(mini, item.second);
            }
            ans += (maxi - mini);
        }
    }
    return ans;
}
```
## DP
```cpp
int perfectSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int notTake = dp[i - 1][t];
            int take = 0;
            if (arr[i - 1] <= t)
                take = dp[i - 1][t - arr[i - 1]];
            dp[i][t] = (take + notTake) % mod;
        }
    }
    return dp[n][target];
}
```
## Recursion
```cpp
int counter(vector<int> &arr, int target, int idx)
{
    if (idx == arr.size())
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }
    int nottake = counter(arr, target, idx + 1);
    int take = counter(arr, target - arr[idx], idx + 1);
    return take + nottake;
}
```

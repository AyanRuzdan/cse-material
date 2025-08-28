## Without DP
```cpp
string longestPalindrome(string s)
{
    int n = s.size();
    int maxi = 1, start = 0;
    auto solve = [&](int left, int right)
    {
        while (left >= 0 && right < n && (s[left] == s[right]))
        {
            if (right - left + 1 > maxi)
            {
                maxi = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    };
    for (int i = 0; i < n; i++)
    {
        solve(i, i);
        solve(i, i + 1);
    }
    return s.substr(start, maxi);
}
```
## With DP
```cpp
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    array<int, 2> ans = {0, 0};
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            ans = {i, i + 1};
        }
    }
     // true value at (i,j) denotes palindromic substring from i to j
    for (int diff = 2; diff < n; diff++)
    {
        for (int i = 0; i < n - diff; i++)
        {
            int j = i + diff;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                ans = {i, j};
            }
        }
    }
    int i = ans[0];
    int j = ans[1];
    return s.substr(i, j - i + 1);
}
/*
     b  a  b  a  d
   d 0  0  1  1  1
   a 0  1  1  2  2
   b 1  1  2  2  2
   a 1  2  2  3  3
   b 1  2  3  3  3
*/
```
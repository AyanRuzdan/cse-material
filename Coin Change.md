You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return _the fewest number of coins that you need to make up that amount_. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

**Example 1:**

**Input:** coins = [1,2,5], amount = 11
**Output:** 3
**Explanation:** 11 = 5 + 5 + 1

**Example 2:**

**Input:** coins = [2], amount = 3
**Output:** -1

**Example 3:**

**Input:** coins = [1], amount = 0
**Output:** 0
```cpp
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto c : coins) {
                if ((i - c) >= 0 && (dp[i - c] != INT_MAX)) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
```
Time Complexity: $O(n\cdot c)$
Space Complexity: $O(n)$
Tags: [[Dynamic Programming]]
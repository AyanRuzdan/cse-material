## Question Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `ith` day.
You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day in the future** to sell that stock.
Return _the maximum profit you can achieve from this transaction_. If you cannot achieve any profit, return `0`.

## Examples

**Example 1:**
>**Input:** prices = [7,1,5,3,6,4]
>**Output:** 5
>**Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
>Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**
>**Input:** prices = [7,6,4,3,1]
>**Output:** 0
>**Explanation:** In this case, no transactions are done and the max profit = 0.

## Approach

Start with initializing two pointers, left and right both to 0. If value at right pointer is greater than value at left pointer, then selling point is found. Calculate maximum profit from the difference and previously calculated max value. If selling point is not found, move left pointer to where the right pointer is. Move right pointer forward every iteration. Return max profit at the end.

## Code
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), left = 0, right = 1;
        int maxProfit = 0;
        while (right < n) {
            if (prices[left] < prices[right]) {
                int profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            } else
                left = right;
            right++;
        }
        return maxProfit;
    }
};
```

Tags: [[Top Interview 150]], [[Arrays]], [[Two Pointers]], [[Sliding Window]]

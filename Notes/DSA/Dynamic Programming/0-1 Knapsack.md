---
cover: https://media.geeksforgeeks.org/wp-content/uploads/20240805101207/Recursion-Tree-for-01-KnapSack.png
---
# 0/1 Knapsack

We are given **N** items where each item has some weight and profit associated with it. We are also given a bag with capacity W, (i.e., the bag can hold at most W weight in it.) The target is to put the items into the bag such that the sum of profits associated with them is the maximum possible.
> **Note:** The constraint here is that we can either put an item completely into the bag or cannot put it at all (It is not possible to put a part of an item into the bag).

For example:

```txt
N=3, W=4, profit = {1,2,3}, weight = {4,5,1}
```

The capacity of the bag is 4, and we have two items which have weight less than or equal to 4. If we select 4kg item then we get profit as 1, and if we select 1kg item then we get profit as 3.
As 3 is the maximum profit, item with weight 1kg will be selected.

Another example where we use the overlapping subproblems method is

```txt
weight = {1,2,3}, profit = {10, 15, 40}
```

|weight&rarr;<br>item(s)&darr;|0|1|2|3|4|5|6|
|-|-|-|-|-|-|-|-|
|0|0|0|0|0|0|0|0|
|1|0|10|10|10|10|10|10|
|2|0|10|15|25|25|25|25|
|3|0|10|15|40|50|55|65|

Code:

```cpp
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return M[n][W];
}
```

The complexity in this case is:
> **TC:** O(N \* W)
> **SC:** O(N \* W)

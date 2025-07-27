## Problem Statement
You are climbing a staircase. It takes `n` steps to reach the top.
Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?
## Examples
**Example 1:**
**Input:** n = 2
**Output:** 2
**Explanation:** There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

**Example 2:**
**Input:** n = 3
**Output:** 3
**Explanation:** There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
## Approach(Recursive/Time Limit Exceeded)
When drawing the recursion tree for the problem, in each level down we have the choice to either step down one step or two steps, giving rise to two branches for each node in the tree until we reach zero. For values of $n\leq2$, we simply return n as those are the base conditions defined. For values $n\gt2$, we can add up the sum of lower level tree nodes. As the time complexity of the code doubles up in each recursive call, we cannot solve the question for larger values of n.
## Code
```cpp
int climbStairs(int n) {
	if (n <= 2)
		return n;
	return climbStairs(n - 1) + climbStairs(n - 2);
}
```
Time Complexity: $O(2^n)$
Space Complexity: $O(1)$
## Approach(Iterative/Dynamic Programming)
In order to solve the question for larger values of n we convert the recursive code into an iterative dynamic programming approach where we define a dp list to contain the steps required for the $n^{th}$ step in the $n^{th}$ index. Then the recurrence relation of the recursive approach is used as list operations and the result for the $n^{th}$ value is derived.
## Code
```cpp
int climbStairs(int n) {
	if(n <= 2) return n;
	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
```
Time Complexity: $O(n)$
Space Complexity: $O(n)$
Tags: [[Recursion]], [[Dynamic Programming]], [[Arrays]]
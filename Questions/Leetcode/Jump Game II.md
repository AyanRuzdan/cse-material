## Question Statement

You are given a **0-indexed** array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.
Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:
- `0 <= j <= nums[i]` and
- `i + j < n`
Return _the minimum number of jumps to reach_ `nums[n - 1]`. The test cases are generated such that you can reach `nums[n - 1]`.

**Example 1:**
>**Input:** nums = [2,3,1,1,4]
>**Output:** 2
>**Explanation:** The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

**Example 2:**
>**Input:** nums = [2,3,0,1,4]
>**Output:** 2

## Approach

Starting from the first index, for the given element, find window where it can jump. Initialize left and right pointers. Then in that window, find the element that can jump the farthest. After iterating each window, left will be updated to first of new window, and right to the farthest index where it can reach, and update new window under {left, right}. Soon right pointer will reach the last index (it is given it will always reach). After every iteration performed to find the largest jump index, increment result. Finally return result.

## Code
```cpp
	int jump(vector<int>& nums) {
        int res = 0;
        int left = 0, right = 0;
        while (right < nums.size() - 1) {
            int farthest = 0;
            for (int i = left; i <= right; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            left = right + 1;
            right = farthest;
            res++;
        }
        return res;
    }
```

Tags: [[Top Interview 150]], [[Arrays]], [[BFS]]
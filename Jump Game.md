## Question Statement

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.
Return `true` _if you can reach the last index, or_ `false` _otherwise_.


## Approach

We traverse the vector using a variable (maxIndex) to store the maximum index we can reach. If we find a 0 inside the array we need to make sure that our maxIndex is higher than the current, if that isn't the case, we'll return False as we won't be able to pass that index, which will prevent us from reaching the end.

If we reach the end we return true.

## Code

```cpp
 bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (maxIndex >= nums.size() - 1)
                return true;
            if (nums[i] == 0 && maxIndex == i)
                return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
```
Tags: [[Top Interview 150]]
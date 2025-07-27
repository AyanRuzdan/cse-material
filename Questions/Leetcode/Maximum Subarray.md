## Problem Statement
Given an integer array `nums`, find the subarray with the largest sum, and return _its sum_.
## Examples
**Example 1:**
**Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]
**Output:** 6
**Explanation:** The subarray [4,-1,2,1] has the largest sum 6.
**Example 2:**
**Input:** nums = [1]
**Output:** 1
**Explanation:** The subarray [1] has the largest sum 1.
**Example 3:**
**Input:** nums = [5,4,-1,7,8]
**Output:** 23
**Explanation:** The subarray [5,4,-1,7,8] has the largest sum 23.
## Approach
Iterating through the array we keep on adding the array elements to our current running sum, if at any point the current running sum falls below zero, then it indicates that it has included negative elements. In order to avoid getting a lower sum, the current running sum is set to zero and a new running sum is calculated from the given point. It is guaranteed that if a negative element has been included that sets the sum to below zero, it will not give the maximum subarray sum, and the best way to avoid that is to move forward in the iteration with setting the current sum to zero.
## Code
```cpp
int maxSubArray(vector<int>& nums) {
	int maxi = INT_MIN;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum > maxi)
			maxi = sum;
		if (sum < 0) {
			sum = 0;
		}
	}
	return maxi;
}
```
Time Complexity: $O(n)$
Space Complexity: $O(1)$
Tags: [[Arrays]]
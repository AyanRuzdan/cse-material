## Problem Statement
Given an array `arr` of integers and a position `m`. You have to reverse the array after that position.
## Examples

Example 1:
> Input: nums = [1,2,3,4,5,6], m = 3
> Output: nums = [1,2,3,4,6,5]

Example 2:
> Input: nums = [10,9,8,7,6], m = 2
> Output: nums = [10,9,8,6,7]

## Approach 1

**Two-pointer approach**: Take the left pointer as `m+1` and right pointer as `n-1` where `n` is the size of the array. Then iterate with the condition `left <= right` and swap `arr[left]` and `arr[right]`. Increment left and decrement right with each swap.

## Code
```cpp
void reverseArray(vector<int>& v, int m){
	int left = m + 1, right = v.size() - 1;
	while(left <= right)
		swap(v[left++],v[right--]);
}
```
Time Complexity: $O(n)$
Space Complexity: $O(1)$
Tags: [[Arrays]], [[Two Pointers]]
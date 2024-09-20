## Question Statement

Given an array/list **ARR** of integers and a position **M**. You have to reverse the array after that position.

## Examples

**Example 1:**
> Input: arr = [1,2,3,4,5,6], m = 3
> Output: arr = [1,2,3,4,6,5]

## Approach

Use a standard two pointer approach to swap the elements of the array, where we specify the left pointer to be `m+1`, and take the right pointer from the right end.

## Code
```cpp
void reverseArray(vector<int> &arr , int m)
{
	int left = m+1, right = arr.size() - 1;
	while(left <= right){
		swap(arr[left++], arr[right--]);
	}
}
```

Time Complexity: $O(m)$
Space Complexity: $O(1)$
Tags: [[Arrays]], [[Two Pointers]]
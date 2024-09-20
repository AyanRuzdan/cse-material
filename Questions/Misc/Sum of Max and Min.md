## Question Statement

You are given an array **ARR** of size **N**. Your task is to find out the sum of maximum and minimum elements in the array.

## Examples

**Example 1:**
> Input: [1,2,4,5,6,6,6]
> Output: 7 (1 + 6)

Example 2:
> Input: [-1,-4,5,8,9,3]
> Output: 5 (-4 + 9)

## Approach

### Sorting
Best way to find the minimum and maximum element is by sorting the array and then picking the first and the last element.
### Code
```cpp
int sumOfMaxMin(int arr[], int n){
	sort(arr, arr+n);
	return arr[0]+arr[n-1];
}
```
Time Complexity: $O(nlogn)$
Space Complexity: $O(1)$
### Traversal of Array
As sorting takes $nlogn$ time complexity, we can simply traverse the array in $O(n)$ to find the minimum and maximum element, and then give the final result.

### Code
```cpp
int sumMinMax(vector<int> &v)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (auto x : v)
    {
        mini = min(mini, x);
        maxi = max(maxi, x);
    }
    return mini + maxi;
}
```
Time Complexity: $O(n)$
Space Complexity: $O(1)$

Tags: [[Arrays]], [[Sorting]]

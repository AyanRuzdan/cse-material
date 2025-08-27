Def: Given a sorted array **arr[]** and a number **target**, the task is to find the **lower bound** of the **target** in this given array.
> **The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number.**

**Note:** If all the elements in the given array are smaller than the **target**, the lower bound will be the length of the array.
## Examples
**Example 1:**
**Input:** arr[] = [2, 3, 7, 10, 11, 11, 25], **target** = 9
**Output:** 3
```cpp
int lowerBound(vector<int> &arr, int target)
{
    int n = arr.size();
    int ans = n;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
```
> Find first index where the given target should be inserted
> Largest value in the array that is just smaller than the target
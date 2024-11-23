## Question Statement
You are given an `m x n` integer matrix `matrix` with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.
Given an integer `target`, return `true` _if_ `target` _is in_ `matrix` _or_ `false` _otherwise_.
You must write a solution in `O(log(m * n))` time complexity.
## Example
**Example 1:**
![](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)
>**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
>**Output:** true
**Example 2:**
![](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)
>**Input:** matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
>**Output:** false

## Approach 1 (One Pass Binary Search)
In order to have a one pass binary search, fix the left pointer at the start of the matrix and the right pointer at the last element of the matrix. In order to find the target element we need to find row and column indices using the formula `row = mid/cols` and `col = mid%cols` where `cols` is the number of cols in the original matrix.
## Code
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows * cols - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (matrix[mid / cols][mid % cols] == target)
                return true;
            else if (matrix[mid / cols][mid % cols] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};
```
Tags: [[Binary Search]]. [[Matrix]]
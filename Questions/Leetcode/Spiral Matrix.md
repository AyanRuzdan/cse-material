## Question Statement
Given an `m x n` `matrix`, return _all elements of the_ `matrix` _in spiral order_.
## Examples
>Example 1:
>![](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)
>Input: matrix = \[[1,2,3],[4,5,6],[7,8,9]]
>Output: [1,2,3,6,9,8,7,4,5]

>Example 2:
>![](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)
>Input: matrix = \[[1,2,3,4],[5,6,7,8],[9,10,11,12]]
>Output: [1,2,3,4,8,12,11,10,9,5,6,7]
## Approach
In order to traverse the matrix in a spiral order, we need to use four different pointers namely left, right, top and bottom. These pointers will be used to traverse the top row, the last column, the bottom row right to left and the first column from bottom to top. Once a layer of the matrix is traversed, the pointers will be moved inwards to traverse the second layer of the spiral. There is also supposed to be a check inside the while loop that the pointers do not cross each other.
## Code
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
```
Tags: [[Arrays]], [[Matrix]]
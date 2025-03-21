## Question Statement
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is `1`, return _the area of the largest rectangle in the histogram_.
## Examples
**Example 1:**
>![](https://assets.leetcode.com/uploads/2021/01/04/histogram.jpg)Input: heights = [2,1,5,6,2,3]
>Output: 10
>Explanation: The above is a histogram where width of each bar is 1. The largest rectangle is shown in the red area, which has an area = 10 units.

**Example 2:**
>![](https://assets.leetcode.com/uploads/2021/01/04/histogram-1.jpg)
>Input: heights = [2,4]
>Output: 4
## Approach
In order to find the maximum area, the best approach is to use a monotonic stack. The stack is made by iterating over the heights and then adding the indices of the heights in a monotonic matter. Whenever a shorter bar is encountered(`heights[st.top()] <= heights[i]`) or the iteration reaches the end (`i` goes till `<=n`), we pop elements from the stack, and simultaneously calculate the height. The width is determined by the difference of the current index and the index of the new top of the stack after popping. If the stack is empty the width extends from the beginning. The iteration continues until all elements have been processed. Finally we return the maximum area that we calculated during each iteration of the while loop.
## Code
```cpp
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                res = max(res, height * width);
            }
            st.push(i);
        }
        return res;
    }
```
Time Complexity: $O(n)$
Space Complexity: $O(n)$
Tags: [[Stacks]]
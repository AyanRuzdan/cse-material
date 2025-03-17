## Question Statement
On a 2D plane, there are `n` points with integer coordinates `points[i] = [xi, yi]`. Return _the **minimum time** in seconds to visit all the points in the order given by_ `points`.

You can move according to these rules:

- In `1` second, you can either:
    - move vertically by one unit,
    - move horizontally by one unit, or
    - move diagonally `sqrt(2)` units (in other words, move one unit vertically then one unit horizontally in `1` second).
- You have to visit the points in the same order as they appear in the array.
- You are allowed to pass through points that appear later in the order, but these do not count as visits.
## Examples
>Example 1:
>![](https://assets.leetcode.com/uploads/2019/11/14/1626_example_1.PNG)
>Input: points = \[[1,1],[3,4],[-1,0]]
>Output: 7
>Explanation: One optimal path is **[1,1]** -> [2,2] -> [3,3] -> **[3,4]** -> [2,3] -> [1,2] -> [0,1] -> **[-1,0]**
>Time from [1,1] to [3,4] = 3 seconds 
>Time from [3,4] to [-1,0] = 4 seconds
>Total time = 7 seconds

>Example 2:
>Input: points = [[3,2],[-2,2]]
>Output: 5

## Approach
It is given that we can start from the first point in the list, so choosing that as the starting point, we iterate the rest of the list. In the list we choose the next point, and then calculate the maximum distance between the x's and y's of the first point and the current point. Absolute difference is mandatory to get the total distance. Once the difference is calculated, now the current point becomes the starting point, and the next point is picked up in the iteration to calculate the distance. The difference method works because we are allowed to move diagonally, which counts as 1 second in time. 
## Code
```cpp
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0; // final answer
        auto start = points[0]; // first point
        for (int i = 1; i < points.size(); i++) { // iterate in the list starting from the second point
            auto first = points[i]; // pick the second point
            res += max(abs(start[0] - first[0]), abs(start[1] - first[1])); // calculate the difference and add it to the result
            start = first; // assign second point as starting in the next iteration
        }
        return res; // return the result
    }
};
```
Tags: [[Arrays]]
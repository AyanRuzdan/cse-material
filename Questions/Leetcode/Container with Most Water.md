## Question Statement
You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return _the maximum amount of water a container can store_.
## Example
![question_11.jpg (801×383)](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)
>**Input:** height = [1,8,6,2,5,4,8,3,7]
>**Output:** 49
>**Explanation:** The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

**Example 2:**
>**Input:** height = [1,1]
>**Output:** 1

## Approach
The total amount of water is calculated by the product of the distance between the bars (given by right pointer - left pointer) and the height of the water contained between the bars (given by max(h\[left\], h\[right\]. In order to get maximum water content, we need to find high bars and max width. Here we use two pointers, for every left bar that is smaller than the right bar, we increment left in hope of finding a taller bar, similarly the right pointer is moved towards the left to find a taller bar. In every iteration the volume of water is calculated and is updated with the max value. At the end of the iteration the maximum water volume is returned.
## Code
```cpp
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int res = 0;
        int n = heights.size(), left = 0, right = n - 1;
        while (left < right)
        {
            res = max(res, (right - left) * min(heights[left], heights[right]));
            if (heights[left] <= heights[right])
                left++;
            else if (heights[left] >= heights[right])
                right--;
            int area = (right - left) * min(heights[left], heights[right]);
            res = max(res, area);
        }
        return res;
    }
};
```
Tags: [[Two Pointers]], [[Arrays]], [[Math]]
## Question Statement
Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.
## Example
**Example 1:**
![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
>**Input:** height = [0,1,0,2,1,0,1,3,2,1,2,1]
>**Output:** 6
>**Explanation:** The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

**Example 2:**
>**Input:** height = [4,2,0,3,2,5]
>**Output:** 9

## Approach 1 (Two Pointer)
The two pointer approach works with dynamically maintaining the largest left and right pointers, and simultaneously calculating the amount of water contained between the current position and the calculated left and right maximums. See in Code.

## Code
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int left = 0, right = height.size() - 1;
        int lMax = height[left], rMax = height[right];
        int res = 0;
        while (left < right) {
            if (lMax < rMax) {
                left++;
                lMax = max(lMax, height[left]);
                res += lMax - height[left];
            } else {
                right--;
                rMax = max(rMax, height[right]);
                res += rMax - height[right];
            }
        }
        return res;
    }
};
```
Tags: [[Arrays]], [[Two Pointers]]
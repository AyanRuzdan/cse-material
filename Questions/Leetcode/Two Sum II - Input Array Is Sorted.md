## Question Statement
Given a **1-indexed** array of integers `numbers` that is already **_sorted in non-decreasing order_**, find two numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index1]` and `numbers[index2]` where `1 <= index1 < index2 <= numbers.length`.

Return _the indices of the two numbers,_ `index1` _and_ `index2`_, **added by one** as an integer array_ `[index1, index2]` _of length 2._

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

## Example
**Example 1:**
>**Input:** numbers = [2,7,11,15], target = 9
>**Output:** [1,2]
>**Explanation:** The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

**Example 2:**
>**Input:** numbers = [2,3,4], target = 6
>**Output:** [1,3]
>**Explanation:** The sum of 2 and 4 is 6. Therefore, index1 = 1, index2 = 3. We return [1, 3].

**Example 3:**
>**Input:** numbers = [-1,0], target = -1
>**Output:** [1,2]
>**Explanation:** The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

## Approach
As the input is already sorted, we can find the target by managing overflow and underflow conditions. By keeping pointers at the left and right ends, we check if the sum of values is larger of smaller than the target. If the sum is larger, then we shift the right pointer to get a smaller sum. Meanwhile if the sum is smaller, we shift the left pointer to approach to a sum closer to the target. 

## Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), left = 0, right = n - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return {left + 1, right + 1};
            if (sum > target)
                right--;
            if (sum < target)
                left++;
        }
        return {};
    }
};
```
Tags: [[Arrays]], [[Two Pointers]]
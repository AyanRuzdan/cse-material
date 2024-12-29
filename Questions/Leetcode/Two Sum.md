## Question Statement: 
Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`_.

You may assume that each input would have **_exactly_ one solution**, and you may not use the _same_ element twice.

You can return the answer in any order.
## Example
**Example 1:**
> **Input:** nums = [2,7,11,15], target = 9
> **Output:** [0,1]
> **Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].

**Example 2:**
> **Input:** nums = [3,2,4], target = 6
> **Output:** [1,2]

**Example 3:**
> **Input:** nums = [3,3], target = 6
> **Output:** [0,1]

## Approach
Make a map that stores the difference of the current element and the target.
If the difference does not exist in the map, then add that difference to the map, else put the index of the difference as the answer.
If the end of the array is reached and the two numbers are not found, then an empty vector is returned.

## Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for(int i=0;i<nums.size();i++){
            if(indices.find(target-nums[i])!=indices.end()){
                return {indices[target-nums[i]], i};
            }
            indices[nums[i]]=i;
        }
        return {};
    }
};
```
Tags: [[Arrays]], [[Maps]]
## Question Statement
Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

## Examples
**Example 1:**
> **Input:** nums = [1,2,3,1]
> **Output:** true

**Example 2:**
> **Input:** nums = [1,2,3,4]
> **Output:** false

**Example 3:**
> **Input:** nums = [1,1,1,3,3,4,3,2,4,2]
> **Output:** true

## Approach
Insert all the elements in a set and compare the size of the set with the size of the vector. If they both are equal then there are no duplicates, otherwise the size of the vector will be larger than the size of the set. Hence it will return false.

## Code
```cpp
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        return !(nums.size() == set(nums.begin(), nums.end()).size());
    }
};
```
Tags: [[Sets]], [[Arrays]]
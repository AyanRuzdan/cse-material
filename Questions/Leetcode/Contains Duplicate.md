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

## Approach 1

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

## Approach 2

Pick element one by one and check if it exists in the hashset, if it exists then return true, else add it to the set. Return false if all elements are unique, which happens at the end of the loop.

## Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end())
            return true;
            else s.insert(nums[i]);
        }
        return false;
    }
};
```
## Approach 3

Sort the array, if any two adjacent elements are the same, then the duplicates exist, otherwise if all elements are unique, then no two adjacent elements will be the same even after sorting.
**Edge case: If the array is empty, then the test case won't work.**
## Code
```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1])
                return true;
        return false;
    }
};
```

Tags: [[Sets]], [[Arrays]], [[Sorting]]

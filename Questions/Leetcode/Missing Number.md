## Question Statement
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return _the only number in the range that is missing from the array._
## Examples
Example 1:
>Input: nums = [3,0,1]
>Output: 2
>Explanation:
>`n = 3` since there are 3 numbers, so all numbers are in the range `[0,3]`. 2 is the missing number in the range since it does not appear in `nums`.

Example 2:
>Input: nums = [0,1]
>Output: 2
>Explanation:
>`n = 2` since there are 2 numbers, so all numbers are in the range `[0,2]`. 2 is the missing number in the range since it does not appear in `nums`.

Example 3:
>Input: nums = [9,6,4,2,3,5,7,0,1]
>Output: 8
>Explanation:
>`n = 9` since there are 9 numbers, so all numbers are in the range `[0,9]`. 8 is the missing number in the range since it does not appear in `nums`.

## Approach 1 (Sum of numbers in list)
If the range is from `[0,n]`, then we can calculate large sum, and then add up the elements of the list. That way the sum would be $\Sigma(n) - \Sigma(list)$ .
### Code
```cpp
int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int sum = (n * (n + 1))/2; // sum can be long long
       return sum - accumulate(nums.begin(), nums.end(), 0); // accumulate is used to find the sum of a list, with starting value as 0 
    }
```
## Approach 2(Sort and search for inconsistency)
If the list is sorted, then there will be a place where two numbers after sorting will differ by 1. There are edge cases involved if the missing number is at the end or at the beginning. In order to work around this edge case, we can match index with the numbers, and find the missing number that way.
### Code
```cpp
int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums[0] != 0)
            return 0;
        if (nums[n - 1] != n)
            return n;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return 0;
    }
```
Tags: [[Math]], [[Arrays]], [[Sorting]]
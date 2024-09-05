## Problem Statement
Given an unsorted array of integers `nums`, return _the length of the longest consecutive elements sequence._
You must write an algorithm that runs in `O(n)` time.
## Examples

**Example 1:**
>**Input:** nums = [100,4,200,1,3,2]
>**Output:** 4
>**Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.

**Example 2:**

> **Input:** nums = [0,3,7,2,5,8,4,6,0,1]
> **Output:** 9

## Approach
**Sets**: Create a new set which contains all elements of the original vector. Now for every number in the set, check if it is a left boundary of a valid sequence. If the set does not contain $(n - 1)$ for a given $n$, then we can take it as a start of a sequence, and continue a sub-iteration with a variable `length`. If $(n + length)$ exists in the set, then we increment `length`, and update a global variable `longest` to $max(longest, length)$.  Finally return the `longest` as the length of the _longest consecutive sequence_.

## Code
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a set that contains all the numbers
        unordered_set<int> myset(nums.begin(), nums.end());
        // global var to contain the final result
        int longest = 0;
        // iterate over the set
        for (auto x : myset) {
            // check if predecessor of a given number, and call it a left boundary
            if (myset.find(x - 1) == myset.end()) {
                // create length variable
                int length = 1;
                // iterate for numbers in a sequence
                while (myset.find(x + length) != myset.end())
                // if number exists, then increment length
                    length++;
                // update value for answer
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
```
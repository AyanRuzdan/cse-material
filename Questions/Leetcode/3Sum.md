## Question Statement
Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.
## Example
**Example 1:**
>**Input:** nums = [-1,0,1,2,-1,-4]
>**Output:** \[[-1,-1,2],[-1,0,1]]
>**Explanation:**
>nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
>nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
>nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
>The distinct triplets are [-1,0,1] and [-1,-1,2].
>Notice that the order of the output and the order of the triplets does not matter.

**Example 2:**
>**Input:** nums = [0,1,1]
>**Output:** []
>**Explanation:** The only possible triplet does not sum up to 0.

**Example 3:**
>**Input:** nums = [0,0,0]
>**Output:** \[[0,0,0]]
>**Explanation:** The only possible triplet sums up to 0.

## Approach
The approach for three-sum is actually quite the same as two-sum, because the target here is always fixed. The problem states that we are not supposed to have same triplets again, which is why sorting the array to skip over same values becomes easy. Once the input is sorted, we can use the approach for [[Two Sum II - Input Array Is Sorted]], where we can use two pointers to reduce the total sum until it actually becomes 0. An outer $O(n)$ loop is necessary to traverse over all elements at least once, meanwhile the inner loop works on the two pointer approach. We also specify methods to skip over same values so that we do not end up with redundant triplets.
## Code
```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // sorting is okay because the expected
        // time complexity is O(n^2) anyway
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
            // if we have a positive number we cannot reduce it to zero
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // skip over same values
            int left = i + 1, right = nums.size() - 1; // THE TWO POINTERS
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // necessary to do overflow and underflow checks
                // before adding triplets to the result
                if (sum > 0) {
                    right--; // reduce the sum
                } else if (sum < 0) {
                    left++; // increase the sum
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // add the triplet and find for other triplets
                    // by closing in the pointers
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++; // skip over same values
                    }
                }
            }
        }
        return res;
    }
};
```

```python
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort() # very critical
        for i, n in enumerate(nums):
            if(n > 0): # first element is positive, can't reduce sum to zero
                break
            if(i > 0 and n == nums[i-1]): # to avoid duplicates
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                curSum = n + nums[l] + nums[r]
                if curSum > 0:
                    r -= 1
                elif curSum < 0:
                    l += 1
                else:
                    res.append([n, nums[l], nums[r]])
                    l += 1
                    while (l < r) and nums[l] == nums[l-1]: # avoid duplicates
                        l += 1
        return res
```
Tags: [[Arrays]], [[Two Pointers]], [[Sorting]]
## Question Statement
Koko loves to eat bananas. There are `n` piles of bananas, the `ith` pile has `piles[i]` bananas. The guards have gone and will come back in `h` hours. Koko can decide her bananas-per-hour eating speed of `k`. Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, she eats all of them instead and will not eat any more bananas during this hour. Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return _the minimum integer_ `k` _such that she can eat all the bananas within_ `h` _hours_.
## Examples
**Example 1:**
>**Input:** piles = \[3,6,7,11], h = 8
>**Output:** 4

**Example 2:**
>**Input:** piles = \[30,11,23,4,20], h = 5
>**Output:** 30

**Example 3:**
>**Input:** piles = \[30,11,23,4,20], h = 6
>**Output:** 23

## Approach
The aim is to find the minimum value of k such that it divides all piles in such a way that the sum is less than required hours. We have to perform a binary search on answer, where k is defined between 1 and the maximum value of the array. If the sum of time taken is less than `h` then we will store that value in final answer and search for an even smaller integer, otherwise we increase the lower limit of k.
## Code
```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while (low <= high) {
            int k = (low + high) / 2;
            long long sum = 0; 
            for (auto pile : piles) {
                sum +=
                    (pile + k - 1) / k; 
            }
            if (sum <= h) {
                ans = k;
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        return ans;
    }
};
```
Tags: [[Arrays]]. [[Binary Search]]
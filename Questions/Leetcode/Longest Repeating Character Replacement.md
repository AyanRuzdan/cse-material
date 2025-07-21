## Question Statement
You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.
Return _the length of the longest substring containing the same letter you can get after performing the above operations_.
## Example
**Example 1:**
>**Input:** s = "ABAB", k = 2
>**Output:** 4
>**Explanation:** Replace the two 'A's with two 'B's or vice versa.

**Example 2:**
>**Input:** s = "AABABBA", k = 1
>**Output:** 4
>**Explanation:** Replace the one 'A' in the middle with 'B' and form "AABBBBA".
>The substring "BBBB" has the longest repeating letters, which is 4.
>There may exists other ways to achieve this answer too.

## Approach
In order to get the same letter in the required substring, all non-frequent characters can be replaced with the most frequent character. And then the replacements can be compared with the `k` value to check if the window is valid or not. We can apply the two pointer approach to maintain windows and keep the frequency of elements. We also need to maintain a `maxFreq` variable to keep track of the most frequent element in the given substring. If the condition for `k` is not satisfied, then we can shift the left pointer and update the frequency map accordingly. To give the result we can maintain the max of the current window length, and window lengths encountered in previous iterations. Basically for every window that contains changeable k non-frequent characters, find the length of the maximum window, as most frequent characters can be many.
## Code
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0;
        int left = 0, maxFreq = 0;
        for (int right = 0; right < s.size(); right++) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);
            while ((right - left + 1) - maxFreq > k) {
            // window size minus maxFreq gives non-frequent elements count
            // those many changes can be made
                mp[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
```
Tags: [[Strings]], [[Two Pointers]], [[Sliding Window]]
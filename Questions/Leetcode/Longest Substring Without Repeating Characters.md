## Question Statement
Given a string `s`, find the length of the **longest substring** without repeating characters.

## Example
**Example 1:**
>**Input:** s = "abcabcbb"
>**Output:** 3
>**Explanation:** The answer is "abc", with the length of 3.

**Example 2:**
>**Input:** s = "bbbbb"
>**Output:** 1
>**Explanation:** The answer is "b", with the length of 1.

**Example 3:**
>**Input:** s = "pwwkew"
>**Output:** 3
>**Explanation:** The answer is "wke", with the length of 3.
>Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

## Approach 
We need to find substring with all unique characters. In order to have all unique characters we can use a `set` of `characters`. Using the two pointer approach we can set both the pointers at the start of the string and increment the right pointer. After every increment of the right pointer we add it to the set and calculate maximum length. If the character is found present in the set, we move the left pointer and erase characters until all the characters in the set are unique again. When the pointers reach the end of the string the maximum substring is found *if any* and its length is returned.
## Code
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        set<char> st;
        for (int right = 0; right < s.size(); right++) {
            while (st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};
```
Tags: [[Strings]], [[Two Pointers]], [[Sliding Window]]
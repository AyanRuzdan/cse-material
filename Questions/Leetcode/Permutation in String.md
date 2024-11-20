## Question Statement
Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.
In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.
## Example
**Example 1:**
>**Input:** s1 = "ab", s2 = "eidbaooo"
>**Output:** true
>**Explanation:** s2 contains one permutation of s1 ("ba").

**Example 2:**
>**Input:** s1 = "ab", s2 = "eidboaoo"
>**Output:** false

## Approach
This question is supposed to be approached via a sliding window approach, an ordered frequency map using a 26 size character array is an optimal approach. Make a character map for the first string. Then for the window of size of the first string, pick the substring of that window size and make it's frequency map. If the character maps match after the selection of the window, then the permutation exists in the selected window, otherwise we move forward and pick a new substring. We can explicitly define a matching function to match the character frequency maps.
## Code
```cpp
class Solution
{
private:
    bool match(int arr1[], int arr2[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
        return false;
        int arr1[26] = {0};
        for (int i = 0; i < s1.length(); i++)
            arr1[s1[i] - 'a']++;
        for (int i = 0; i <= s2.length() - s1.length(); i++)
        {
            int arr2[26] = {0};
            for (int j = 0; j < s1.length(); j++)
            {
                arr2[s2[i + j] - 'a']++;
            }
            if (match(arr1, arr2))
                return true;
        }
        return false;
    }
};
```
Tags: [[Strings]], [[Sliding Window]], [[Maps]]
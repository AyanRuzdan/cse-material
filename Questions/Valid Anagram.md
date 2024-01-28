## Question Statement
Given two strings `s` and `t`, return `true` _if_ `t` _is an anagram of_ `s`_, and_ `false` _otherwise_.

## Examples
**Example 1:**
**Input:** s = "anagram", t = "nagaram"
**Output:** true

**Example 2:**
**Input:** s = "rat", t = "car"
**Output:** false

## Approach 1
Sort both the strings and compare character by character, return false if characters are not the same.
## Code
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t) return true;
        else return false;
    }
};
```

## Approach 2
Pick character one by one and increase frequency in the map. Do it for both the strings. Then iterate on the map and compare, return false if match not found.

## Code
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> s1;
        unordered_map<char, int> t1;
        for(int i = 0; i < s.size(); i++)
        {
            s1[s[i]]++;
            t1[t[i]]++;
        }
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != t1[i]) return false;
        }
        return true;
    }
};
```
Tags: [[Sets]], [[Strings]], [[Maps]]
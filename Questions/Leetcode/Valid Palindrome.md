## Question Statement
A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` _if it is a **palindrome**, or_ `false` _otherwise_.

## Example
**Example 1:**
>**Input:** s = "A man, a plan, a canal: Panama"
>**Output:** true
>**Explanation:** "amanaplanacanalpanama" is a palindrome.

**Example 2:**
>**Input:** s = "race a car"
>**Output:** false
>**Explanation:** "raceacar" is not a palindrome.

**Example 3:**
>**Input:** s = " "
>**Output:** true
>**Explanation:** s is an empty string "" after removing non-alphanumeric characters.
>Since an empty string reads the same forward and backward, it is a palindrome.

## Approach 1
To verify that a given string is a palindrome, it is best to use two pointers that run from both the left and right end of the string. In this question there are both whitespaces and special symbols, so if we encounter them we can just skip, but the characters are *alnum*, then we need to check if they are the same or not.

## Code
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), l=0, r=n-1;
        while(l<r){
            while(l<r && !isalnum(s[l]))
            l++;
            while(l<r && !isalnum(s[r]))
            r--;
            if(tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
```

## Approach 2
If the string does not contain anything except *alnum* characters, then we can make a copy of the original string, reverse it, and then compare it character by character. In the case of existence of special characters, we need to skip over them and only work upon the *alnum* characters.

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string new1 = "";
        for (char c : s) {
            if (isalnum(c)) {
                new1 += tolower(c);
            }
        }
        return new1 == string(new1.rbegin(), new1.rend());
    }
};
```
Tags: [[Strings]], [[Two Pointers]]
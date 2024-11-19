## Question Statement
Given two strings `s` and `goal`, return `true` _if and only if_ `s` _can become_ `goal` _after some number of **shifts** on_ `s`.
A **shift** on `s` consists of moving the leftmost character of `s` to the rightmost position.
- For example, if `s = "abcde"`, then it will be `"bcdea"` after one shift.

## Examples
**Example 1:**
>**Input:** s = "abcde", goal = "cdeab"
>**Output:** true

**Example 2:**
>**Input:** s = "abcde", goal = "abced"
>**Output:** false

## Approach
## Easy Approach
If the goal and input are the same then continue. Concatenate the input to itself. After concatenation, find the goal string inside the concatenated string. If the elements of s are in the same order as goal, then due to concatenation, there will be window where the goal exists inside the concatenated string. The code makes it a bit more understandable.

### Code
```cpp
bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s+s).find(goal) != string::npos;
    }
```
## Knuth-Morris-Pratt (KMP)
I don't want to do this.
Tags: [[Strings]]
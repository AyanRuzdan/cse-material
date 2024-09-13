## Question Statement
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## Examples
**Example 1:**
> **Input:** s = "()"
> **Output:** true

**Example 2:**
> **Input:** s = "()[]{}"
> **Output:** true

**Example 3:**
> **Input:** s = "(]"
> **Output:** false

## Approach
This code uses a stack for the given approach. For each character in the string, if it an opening bracket, then it is pushed into the stack. If the character is a closing bracket, then it is checked if the stack is empty or not. If the stack is empty then the brackets are not balanced and the code returns false. Otherwise, the code pops off the top character and checks if the given character was a matching character for the current closing bracket. If it is true, then we continue iterating over the entire string, else the brackets are not balanced and we return false again.
## Code
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
```
Tags: [[Stacks]]
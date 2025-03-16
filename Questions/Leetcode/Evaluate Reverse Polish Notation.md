## Question Statement

You are given an array of strings `tokens` that represents an arithmetic expression in a [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).
Evaluate the expression. Return _an integer that represents the value of the expression_.
**Note** that: 

- The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
- Each operand may be an integer or another expression.
- The division between two integers always **truncates toward zero**.
- There will not be any division by zero.
- The input represents a valid arithmetic expression in a reverse polish notation.
- The answer and all the intermediate calculations can be represented in a **32-bit** integer.

## Example

**Example 1:**
>**Input:** tokens = ["2","1","+","3","*"]
>**Output:** 9
>**Explanation:** ((2 + 1) * 3) = 9
**Example 2:**
>**Input:** tokens = ["4","13","5","/","+"]
>**Output:** 6
>**Explanation:** (4 + (13 / 5)) = 6

**Example 3:**
>**Input:** tokens = \["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
>**Output:** 22
>**Explanation:** ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
>= ((10 * (6 / (12 * -11))) + 17) + 5
>= ((10 * (6 / -132)) + 17) + 5
>= ((10 * 0) + 17) + 5
>= (0 + 17) + 5
>= 17 + 5
>= 22

## Approach

Use a stack to evaluate the expression. If a number comes up then push it into the stack, if any operator is encountered in the token list then fetch the top two elements of the stack, perform operation on them and push them back into the stack. In the end return the top of the stack (assuming here that the token expression is always valid)

## Code

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto item : tokens) {
            if (item == "+" || item == "-" || item == "*" || item == "/") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                if (item == "+") {
                    st.push(n1 + n2);
                }
                if (item == "-") {
                    st.push(n2 - n1);
                }
                if (item == "*") {
                    st.push(n1 * n2);
                }
                if (item == "/") {
                    st.push(n2 / n1);
                }
            } else {
                st.push(stoi(item));
            }
        }
        return st.top();
    }
};
// CASE VERSION
/*
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto item : tokens) {
            if (item == "+" || item == "-" || item == "*" || item == "/") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                switch (item[0]) {
                case '+':
                    st.push(n2 + n1);
                    break;
                case '-':
                    st.push(n2 - n1);
                    break;
                case '*':
                    st.push(n2 * n1);
                    break;
                case '/':
                    st.push(n2 / n1);
                    break;
                }
            } else {
                st.push(stoi(item));
            }
        }
        return st.top();
    }
};
*/
```
Tags: [[Stacks]]
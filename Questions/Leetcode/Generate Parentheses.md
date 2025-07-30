## Question Statement
Given `n` pairs of parentheses, write a function to _generate all combinations of well-formed parentheses_.
## Examples
Example 1:
> Input: n = 3
> Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
> Input: n = 1
> Output ["()"]
## Approach
Using a recursive approach, we pass the parameters of the open and close count, the limit of the open and close count, an empty string and the vector that will contain all the valid arrangements.
In the recursive function, if open and close count both will be equal to n, then we will push the string in the vector.
If the count of open brackets will be less than n, the we will continue in the recursion with an open bracket added in the string.
Similarly if the count of closing brackets will be less than the count of the open brackets, we will add a closing bracket to the string and continue with the recursion.
The return condition will be handled when both open and close count will become equal to maximum allowed value.
## Code
```cpp
void generate(int n, int open, int close, string str, vector<string>& res) {
        if (close == n && open == n) {
            res.push_back(str);
        }
        if (open < n) {
            generate(n, open + 1, close, str + "(", res);
        }
        if (close < open) {
            generate(n, open, close + 1, str + ")", res);
        }
    }
vector<string> generateParenthesis(int n) {
    vector<string> res;
    generate(n, 0, 0, "", res);
    return res;
    }
```
Tags: [[Strings]], [[Recursion]], [[Backtracking]]

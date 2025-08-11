## Question Statement
Given a string `s`, you can transform every letter individually to be lowercase or uppercase to create another string.
Return _a list of all possible strings we could create_. Return the output in **any order**.
## Examples
>**Example 1:**
>**Input:** s = "a1b2"
>**Output:** ["a1b2","a1B2","A1b2","A1B2"]

>**Example 2:**
>**Input:** s = "3z4"
>**Output:** ["3z4","3Z4"]
## Approach (Recursive)
A recursive approach where every alphabetical character is switched case and then with the modified string a recursive call is made with incremented index. When the index reaches the end of the string all case switches in that branch of the recursion call are done, and the modified string with the switched case is inserted into the resultant list.
## Code
```cpp
    void solve(vector<string>& res, string& s, int idx) {
        if (idx == s.size()) {
            res.push_back(s);
            return;
        }
        if (isalpha(s[idx])) {
            s[idx] = tolower(s[idx]);
            solve(res, s, idx + 1);
            s[idx] = toupper(s[idx]);
            solve(res, s, idx + 1);
        } else
            solve(res, s, idx + 1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(res, s, 0);
        return res;
    }
```
Time Complexity: $O(2^n)$
Space Complexity: $O(2^n)$
Tags: [[Recursion]], [[Backtracking]], [[Strings]]
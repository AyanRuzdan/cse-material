## Question Statement
Given two integers `n` and `k`, return _all possible combinations of_ `k` _numbers chosen from the range_ `[1, n]`.

You may return the answer in **any order**.
## Examples
**Example 1:**

**Input:** n = 4, k = 2
**Output:** \[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
**Explanation:** There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

**Example 2:**

**Input:** n = 1, k = 1
**Output:** \[[1]]
**Explanation:** There is 1 choose 1 = 1 total combination.
## Approach (Backtracking)
The approach begins by establishing a base condition: once the current combination reaches exactly `k` elements, it is added to the result. The solution uses backtracking to explore all possibilities. Each combination is built as a list of increasing elements, with every new combination starting from an incremented number to maintain order and avoid duplicates. This ordering is enforced by controlling the left boundary of the search through the recursive call, where the `for` loop’s starting index is updated according to the current recursion depth. After adding an element, the algorithm recursively explores further options, and once that path is processed, it removes the last element (`pop_back`) to backtrack. This ensures the loop continues exploring all remaining possibilities until all valid combinations are generated.
## Code
```cpp
    void solve(int n, int k, vector<int>& temp, vector<vector<int>>& res,
               int start) {
        if (temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(n, k, temp, res, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(n, k, temp, res, 1);
        return res;
    }
```
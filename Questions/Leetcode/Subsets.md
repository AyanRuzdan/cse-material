## Question Statement
Given an integer array `nums` of **unique** elements, return _all possible subsets (the power set)_.
The solution set **must not** contain duplicate subsets. Return the solution in **any order**.
## Examples
>**Example 1:**
>**Input:** nums = [1,2,3]
>**Output:** [\[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

>**Example 2:**
>**Input:** nums = [0]
>**Output:** [\[],[0]]

## Approach 1
A recursion based approach of inclusion-exclusion can be used here where either an index can be selected or left behind to be included in a subset, and then the index is moved forward. After the path of inclusion-exclusion is done, the index reaches the end of the array, at that point the subset is pushed into the power set.
## Code
```cpp
class Solution {
public:
    void gen(vector<int> nums, vector<vector<int>>& res, int index,
             vector<int> temp) {
        // general overflow base case
        if (index >= nums.size()) {
            res.push_back(temp);
            return;
        }
        // exclusion
        gen(nums, res, index + 1, temp);
        // inclusion
        temp.push_back(nums[index]);
        gen(nums, res, index + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        gen(nums, res, 0, temp);
        return res;
    }
};
```

## Approach 2 (Backtracking)
A recursion-based approach using backtracking can be used here, where for each index, all subsets starting from that index are explored by adding the current element to a temporary subset and recursively moving forward. After exploring, the current element is removed (backtracking) to explore other possibilities. At each recursive call, the current subset is added to the power set.
## Code
```cpp
class Solution {
private:
    void subsets(vector<int>& nums, int index, vector<int>& sub,
                 vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = index; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
};
```

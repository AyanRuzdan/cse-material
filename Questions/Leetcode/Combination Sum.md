## Question Statement
Given an array of **distinct** integers `candidates` and a target integer `target`, return _a list of all **unique combinations** of_ `candidates` _where the chosen numbers sum to_ `target`_._ You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.
## Examples
>Example 1:
>Input: candidates = [2,3,6,7], target = 7
>Output: \[[2,2,3],[7]]
>Explanation:
>2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
>7 is a candidate, and 7 = 7.
>These are the only two combinations.

>Example 2:
>Input: candidates = [2,3,5], target = 8
>Output: \[[2,2,2,2],[2,3,3],[3,5]]

>Example 3:
>Input: candidates = [2], target = 1
>Output: []
## Approach
In this question we can use the same number any number of times until the given sum is reached. In order to achieve that using inclusion-exclusion approach, we will recur with the addition of the number in the `nums`, but not continuing with the index. Meanwhile in the next case we will `pop_back` the included number and continue with the number coming next in the list. Finally when we reach the end of the list, we return.
```cpp
void helper(vector<vector<int>> &res, vector<int> &temp,
            vector<int> &candidates, int target, int idx)
{
    if (idx == candidates.size())
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        else
        {
            return;
        }
    }
    if (candidates[idx] <= target)
    {
        temp.push_back(candidates[idx]);
        helper(res, temp, candidates, target - candidates[idx], idx);
        temp.pop_back();
    }
    helper(res, temp, candidates, target, idx + 1);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    int idx = 0;
    helper(res, temp, candidates, target, idx);
    return res;
}
```
TagsL [[Recursion]]
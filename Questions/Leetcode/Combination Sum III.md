```cpp
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    vector<vector<int>> res;
    vector<int> temp;
    backtrack(res, temp, candidates, target, 0);
    return res;
}
void backtrack(vector<vector<int>> &res, vector<int> &temp,
               vector<int> &candidates, int target, int index)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = index; i < candidates.size() && target >= candidates[i];
         ++i)
    {
        if (i == index || candidates[i] != candidates[i - 1])
        {
            temp.push_back(candidates[i]);
            backtrack(res, temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
}
```
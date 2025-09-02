```cpp
void solve(vector<vector<int>> &res, vector<int> &temp, vector<int> &v,
           int idx)
{
    res.push_back(temp);
    for (int i = idx; i < v.size(); ++i)
    {
        if (i > idx && v[i] == v[i - 1])
            continue;
        temp.push_back(v[i]);
        solve(res, temp, v, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    solve(res, temp, nums, 0);
    return res;
}
```
Tags: [[Recursion]]

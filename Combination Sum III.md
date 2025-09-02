```cpp
void solve(vector<vector<int>> &res, vector<int> &temp, int k, int n,
           int idx)
{
    if (temp.size() == k)
    {
        if (n == 0)
        {
            res.push_back(temp);
            return;
        }
        else if (n < 0)
            return;
    }
    for (int i = idx; i <= 9; i++)
    {
        temp.push_back(i);
        solve(res, temp, k, n - i, i + 1);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> temp;
    solve(res, temp, k, n, 1);
    return res;
}
```
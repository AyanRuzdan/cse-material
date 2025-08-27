```cpp
vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int cnt_max = -1;
    int index = -1;
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        sort(mat[i].begin(), mat[i].end());
        auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);
        int cnt_ones = mat[i].size() - (it - mat[i].begin());
        if (cnt_ones >
            cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return {index, cnt_max};
}
```

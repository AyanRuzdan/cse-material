```cpp
int median(vector<vector<int>> &mat)
{
    int r = mat.size();
    int c = mat[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][c - 1]);
    }
    int desired_idx = (r * c + 1) / 2;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < r; i++)
        {
            count += (upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin());
        }
        if (count < desired_idx)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}
```

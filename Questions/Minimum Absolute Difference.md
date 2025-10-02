```cpp
vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    vector<vector<int>> res;
    ranges::sort(arr);
    int diff = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        diff = min(diff, arr[i + 1] - arr[i]);
    }
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] == diff)
        {
            res.push_back({arr[i - 1], arr[i]});
        }
    }
    return res;
}
```
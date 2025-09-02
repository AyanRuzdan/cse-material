```cpp
bool helper(int n, vector<int> &arr, int k, int idx)
{
    if (idx == n)
    {
        if (k == 0)
        {
            return true;
        }
        else
            return false;
    }
    return helper(n, arr, k - arr[idx], idx + 1) || helper(n, arr, k, idx + 1);
}
```

```cpp
int minSubArrayLen(int target, vector<int> &nums)
{
    int l = 0, res = INT_MAX, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        while (sum >= target)
        {
            res = min(res, (i - l + 1));
            sum -= nums[l];
            l++;
        }
    }
    if (res == INT_MAX)
        return 0;
    else
        return res;
}
```
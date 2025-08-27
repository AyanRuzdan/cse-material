```cpp
int solve(vector<int> &weights, int capacity)
{
    int load = 0, days = 1;
    for (auto weight : weights)
    {
        if (load + weight > capacity)
        {
            days += 1;
            load = weight;
        }
        else
        {
            load += weight;
        }
    }
    return days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (solve(weights, mid) <= days)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
```

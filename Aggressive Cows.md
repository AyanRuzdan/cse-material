```cpp
bool canPlace(vector<int> &stalls, int dist, int cows)
{
    int lastCow = stalls[0];
    int cowCount = 1;
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastCow >= dist)
        {
            cowCount++;
            lastCow = stalls[i];
        }
        if (cowCount >= cows)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    // code here
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;
        if (canPlace(stalls, mid, k))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
```

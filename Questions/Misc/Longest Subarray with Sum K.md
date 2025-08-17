```cpp
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int maxLen = 0;
    int l = 0, r = 0;
    int n = a.size();
    long long sum = a[0];
    while(r < n){
        while(l <= r && sum > k){
            sum -= a[l];l++;
        }
        if(sum == k){
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
        if(r < n){
        sum += a[r];
        }
    }
    return maxLen;
}
```
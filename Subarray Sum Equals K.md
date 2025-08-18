```cpp
int subarraySum(vector<int>& a, int k) {
        int n = a.size(); 
        map<int,int> mpp;
        int preSum = 0, cnt = 0;
        mpp[0] = 1; 
        for (int i = 0; i < n; i++) {
            preSum += a[i];
            int remove = preSum - k;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }
```
```cpp
long subarrayXor(vector<int> &arr, int k) {
        int xr = 0;
        map<int,int> mp;
        mp[xr]++;
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            xr = xr ^ arr[i];
            int x = xr ^ k;
            count += mp[x];
            mp[xr]++;
        }
        return count;
    }
```
```cpp
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> res;
        res.push_back(arr.back());
        int new_max = arr.back();
        for(int i = arr.size() - 1; i > 0; i--){
            if(arr[i-1] >= new_max){
                res.push_back(arr[i-1]);
                new_max = arr[i-1];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
```
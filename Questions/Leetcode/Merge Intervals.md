```cpp
vector<vector<int>> merge(vector<vector<int>>& ints) {
        vector<vector<int>> res;
        sort(ints.begin(), ints.end());
        for(auto inte:ints){
            if(res.empty() || res.back()[1] < inte[0]) res.push_back(inte);
            else{
                res.back()[1] = max(res.back()[1], inte[1]);
            }
        }
        return res;
    }
```
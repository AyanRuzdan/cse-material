## Code
```cpp
vector<int> sortedSquares(vector<int>& nums) {
        vector<int> negs;
        vector<int> pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                negs.push_back(nums[i] * nums[i]);
            else
                pos.push_back(nums[i] * nums[i]);
        }
        reverse(negs.begin(), negs.end());
        vector<int> res;
        int i = 0, j = 0, n1 = negs.size(), n2 = pos.size();
        while (i < n1 && j < n2) {
            if (negs[i] < pos[j]) {
                res.push_back(negs[i++]);
            } else
                res.push_back(pos[j++]);
        }
        while (i < n1) {
            res.push_back(negs[i++]);
        }
        while (j < n2)
            res.push_back(pos[j++]);
        return res;
    }
```

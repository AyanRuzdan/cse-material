```cpp
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, n;
        for (auto x : nums) {
            if (x >= 0)
                p.push_back(x);
            else
                n.push_back(x);
        }
        vector<int> res;
        int size1 = p.size();
        int size2 = n.size();
        int i = 0;
        while (size1-- && size2--) {
            res.push_back(p[i]);
            res.push_back(n[i]);
            i++;
        }
        return res;
    }
```
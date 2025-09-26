```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> st;
        map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            // aage jae ya peeche, algo works the same
            int ele = nums2[i];
            while (!st.empty() && ele > st.top()) {
                mp[st.top()] = ele;
                st.pop();
            }
            st.push(ele);
        }
        for (int i = 0; i < nums1.size(); i++) {
            int ele = nums1[i];
            if (mp.find(ele) != mp.end()) {
                int temp = mp[ele];
                res[i] = temp;
            }
        }
        return res;
    }
```
Tags: [[Stacks]]
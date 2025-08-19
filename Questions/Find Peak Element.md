```cpp
   int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1)
            return 0; // return index of peak na
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 2] < nums[n - 1])
            return n - 1;
        int l = 1, r = n - 2;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return -1;
    }
```

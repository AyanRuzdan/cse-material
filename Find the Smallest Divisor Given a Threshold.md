```cpp
   int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (high - low) / 2 + low;
            int sum = 0;
            for (auto num : nums) {
                sum += ceil((num * 1.0) / mid);
            }
            if (sum > threshold) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return low;
    }
```
Tags: [[Binary Search on Answer]]
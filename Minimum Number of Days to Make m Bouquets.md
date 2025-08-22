```cpp
 int solve(int mid, int m, int k, vector<int>& nums){
        int count = 0;
        int n = nums.size();
        int bouq = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= mid){
                count++;
            }else{
                bouq += (count/k);
                count = 0;
            }
        }
        bouq += (count/k);
        return bouq >= m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        long long val = m * k;
        if(val > nums.size()) return -1;
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        while(left <= right){
            int mid = (right - left)/2 + left;
            if(solve(mid, m, k, nums)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
```
Tags: [[Binary Search]]
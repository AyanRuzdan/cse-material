```cpp
int first(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target){
            ans = mid; high = mid - 1;
        }
        else if(target > nums[mid])
        low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
int last(vector<int>& nums, int target){
    int low = 0; int high = nums.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target){
            ans = mid;
            low = mid+1;
        }
        else if(target>nums[mid])
        low = mid+1;
        else high = mid-1;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int first_index = first(nums, target);
        int last_index = last(nums, target);
        res[0] = first_index;
        res[1] = last_index;
        return res;
    }
```
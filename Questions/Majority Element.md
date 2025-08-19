## Moore's Voting Algorithm
```cpp
int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
            if(count == 0) {
            ele = nums[i];
            count++;
            }
        }
        return ele;
    }
```
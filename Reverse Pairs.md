```cpp
void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;      // pointer for left half
        int right = mid + 1; // pointer for right half
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        // Add remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);
        // Add remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);
        // Copy back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > 2LL * nums[right])
                right++;
            count += (right - (mid + 1));
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int begin, int end) {
        int count = 0;
        if (begin >= end)
            return count; // base case: one element
        int mid = begin + (end - begin) / 2;
        count += mergeSort(arr, begin, mid);   // sort left half
        count += mergeSort(arr, mid + 1, end); // sort right half
        count += countPairs(arr, begin, mid, end);
        merge(arr, begin, mid, end); // merge sorted halves
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
```
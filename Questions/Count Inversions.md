```cpp
int merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int count = 0;
    int left = low;       // pointer for left half
    int right = mid + 1;  // pointer for right half
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else{
            temp.push_back(arr[right++]);
            count += (mid - left + 1);
        }
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
    return count;
}

int mergeSort(vector<int>& arr, int begin, int end) {
    int count = 0;
    if (begin >= end)
        return count; // base case: one element
    int mid = begin + (end - begin) / 2;
    count += mergeSort(arr, begin, mid);     // sort left half
    count += mergeSort(arr, mid + 1, end);   // sort right half
    count += merge(arr, begin, mid, end);    // merge sorted halves
    return count;
}
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr, 0, arr.size()-1);
    }
```
The merge sort algorithm is a sorting algorithm that is based on the **Divide and Conquer** paradigm. The array is initially divided into two equal halves and then they are combined in a sorted manner.
**Time Complexity** : $O(nlogn)$
## Working
It is a recursive algorithm that continuously splits the array in half until it cannot be further divided.
```txt
 step1: start
 step2: declare array and left, right, mid variable
 step3: perform merge function
 		if (left>right)
 			return
 		set mid:=(left+right)/2
 		Call mergeSort(array, left, mid)
 		Call mergeSort(array, mid+1, right)
 		Call merge(array, left, mid, right) step4: stop
 ```

```cpp
void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;       // pointer for left half
    int right = mid + 1;  // pointer for right half
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

void mergeSort(vector<int>& arr, int begin, int end) {
    if (begin >= end)
        return; // base case: one element
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);     // sort left half
    mergeSort(arr, mid + 1, end);   // sort right half
    merge(arr, begin, mid, end);    // merge sorted halves
}
```
Tags: [[Sorting]], [[Merging]]
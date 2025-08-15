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
void merge(vector<int>& arr, int low, int mid, int high){
	vector<int> temp;
	int left = low; // low se mid tak pehla array
	int right = mid + 1; // mid+1 se high tak doosra array
	while(left <= mid && right <= high){
		if(arr[left] <= arr[right])
			temp.push_back(arr[left++]);
		else
			temp.push_back(arr[right++]);
	}
	// either of them will exhaust, so one loop for each, no matter
	while(left <= mid)
		temp.push_back(arr[left++]);

	while(right <= high)
		temp.push_back(arr[right++]);
	// copy elements back into the original array
	for(int i = low; i <= high; i++)
		arr[i] = temp[i - low]; // as we are not returning temp, we fill in back into arr
}	

void mergeSort(int arr[], int begin, int end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}
```
Tags: [[Sorting]], [[Merging]]
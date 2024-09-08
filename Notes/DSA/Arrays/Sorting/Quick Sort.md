The **QuickSort** algorithm is a sorting algorithm that is based on the **Divide and Conquer** paradigm. It picks an element as a pivot and partitions the given array around the pivot. The key process in QuickSort is the `partition()` function. The goal of the partition is, given an array and an element `x` of the array as the pivot, to place `x` at its correct position in a sorted array, putting all smaller elements before `x` and all greater elements after `x`. This is done in linear time.
### Time Complexity
 - Average Case: $O(n logn)$
 - Worst case: $O(n^2)$
### Working
QuickSort is a recursive algorithm that continuously partitions the array and sorts the sub-arrays. The array is divided into smaller sub-arrays based on the pivot, and QuickSort is recursively called on these sub-arrays.
```
step1: start
step2: declare array and low, high, and pivot variables
step3: perform partition function
	   if (low >= high)
		   return
		set pivot := partition(array, low, high)
		Call quickSort(arr, low, pivot - 1)
		Call quickSort(arr, pivot + 1, high)
step4: stop
```

### QuickSort() function
The `quickSort()` function recursively sorts the array by selecting a pivot and partitioning the array around the pivot.
```
low = starting index
high = ending index
quickSort(arr[], low, high){
	if(low < high){
		pi = partition(arr, low, high)
		quickSort(arr, low, pi - 1)
		quickSort(arr, pi + 1, high)
	}
}
```

### Partition() function
The `partition()` function places the pivot element at its correct position in the sorted array, with all smaller elements placed to the left and all greater elements to the right.
```
partition(arr[], low, high){
	pivot = arr[low]
	i = low - 1
	for(j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++
			swap(arr[i], arr[j])
		}
	}
	swap(arr[i+1], arr[high])
	return (i+1)
}
```

### Code
```cpp
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the rightmost element as pivot
    int i = (low - 1);    // Pointer for the greater element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot) // If the current element is smaller than the pivot
        {
            i++;
            swap(arr[i], arr[j]); // Swap smaller element with the greater element
        }
    }
    swap(arr[i + 1], arr[high]); // Swap the pivot with the greater element
    return (i + 1);              // Return the partition point
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);  // Recursively sort the left sub-array
    quickSort(arr, pivot + 1, high); // Recursively sort the right sub-array
}
```

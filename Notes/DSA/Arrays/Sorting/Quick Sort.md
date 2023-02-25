It is an QuickSort algorithm. It picks an element as a pivot and partitions the given array around the picked pivot. The key process QuickSort is a `partition()`. The target of partitions is, given an array and an element x of an array as the pivot, put x at its correct position in a sorted array and put all smaller elements before x, and put all greater elements after x. All this is done in linear time.
## QuickSort() function
```txt
low = starting index
high = ending index
quickSort(arr[], low, high){
	if (low<high){
		pi = partition(arr, low, high)
		quickSort(arr, low, pi-1)
		quickSort(arr, pi+1, high)
	}
}
```
## Partition() function
```txt
partition(arr[], low, high)
{
	pivot = arr[high]
	i = low-1
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<pivot)
		{
			i++
			swap(arr[i] and arr[j])
		}
	}
	swap(arr[i+1] and arr[high])
	return (i+1)
}
```
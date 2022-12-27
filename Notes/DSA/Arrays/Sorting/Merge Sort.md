The merge sort algorithm is a sorting algorithm that is based on the **Divide and Conquer** paradigm. The array is initially divided into two equal halves and then they are combined in a sorted manner.
## Working
It is a recursive algorithm that continuosly splits the array in half unitl it cannot be further divided.
> ```txt
> step1: start
> step2: declare array and left, right, mid variable
> step3: perform merge function
> 		if (left>right)
> 			return
> 		set mid:=(left+right)/2
> 		Call mergeSort(array, left, mid)
> 		Call mergeSort(array, mid+1, right)
> 		Call merge(array, left, mid, right)
> step4: stop
> ```
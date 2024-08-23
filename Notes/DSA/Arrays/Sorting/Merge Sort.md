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
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    auto subArrOne = mid - left + 1;
    auto subArrTwo = right - mid;

    auto *leftArr = new int[subArrOne];
    auto *rightArr = new int[subArrTwo];

    for (int i = 0; i < subArrOne; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < subArrTwo; i++)
        rightArr[i] = arr[mid + 1 + i];
    auto indexSubArrOne = 0, indexSubArrTwo = 0;
    int indexMergedArr = left;
    while (indexSubArrOne < subArrOne && indexSubArrTwo < subArrTwo)
    {
        if (leftArr[indexSubArrOne] <= rightArr[indexSubArrTwo])
        {
            arr[indexMergedArr] = leftArr[indexSubArrOne];
            indexSubArrOne++;
        }
        else
        {
            arr[indexMergedArr] = rightArr[indexSubArrTwo];
            indexSubArrTwo++;
        }
        indexMergedArr++;
    }
    while (indexSubArrOne < subArrOne)
    {
        arr[indexMergedArr] = leftArr[indexSubArrOne];
        indexSubArrOne++;
        indexMergedArr++;
    }
    while (indexSubArrTwo < subArrTwo)
    {
        arr[indexMergedArr] = rightArr[indexSubArrTwo];
        indexSubArrTwo++;
        indexMergedArr++;
    }
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

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    cout << "The sorted array: ";
    printArray(arr, n);
    return 0;
}
```
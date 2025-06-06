# Selection Sort
**Time Complexity: $O(n^2)$**
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending sort order) from the unsorted part and putting it at the beginning. The algorithm contains two subarrays:
* Already sorted subarray
* Remaining unsorted subarray
In every iteration, the minimum element (considering ascending sort order) from the unsorted subarray is picked and moved to the sorted subarray.
For example if there is an integer array = {64, 25, 12, 22, 11}, then the sorting order would be
```cpp
{64, 25, 12, 22, 11} //initial position
{11, 25, 12, 22, 64} //64 gets swapped with 11
{11, 12, 25, 22, 64} //25 gets swapped with 12
{11, 12, 22, 25, 64} //25 gets swapped with 22
{11, 12, 22, 25, 64} //As 25 is less than 64, no swap is required
```
## Approach
* Initialize minimum value(`min_index`) to first index.
* Traverse the array to find the minimum element.
* If any element smaller than `min_index` is found, then swap both values.
* Increment `min_index` to point to the next element.
* Repeat until array is sorted.
Code in C++:
```cpp
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(arr[min_idx], arr[i]);
    }
}
```
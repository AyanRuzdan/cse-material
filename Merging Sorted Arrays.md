Merging two sorted tasks is a prerequisite for merge sort and other merge based algorithms.
```cpp
arr1[] = {1,3,4,5}, arr2[] = {2,4,6,8}
arr3[] = {arr1[], arr2[]}
	   = {1,2,3,4,4,5,6,8}
```
The brute force approach to merging is to insert all the elements of both the arrays into a final array and then sorting the array in the end.
```cpp
void merge(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    // push elements of the first array {arr1} into arr3
    while (i < n1)
        arr3[k++] = arr1[i++];
    // push elements of the second array {arr2} into arr3
    while (j < n2)
        arr3[k++] = arr2[j++];
    // sort using STL
    sort(arr3, arr3 + n1 + n2);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    // initialize arrays that are to be merged
    int arr1[] = {1, 3, 5, 7}, arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]), n2 = sizeof(arr2) / sizeof(arr1[0]);
    // initialize final array of cumulative size
    int arr3[n1 + n2];
    // call merge function
    merge(arr1, arr2, n1, n2, arr3);
    printArray(arr3, n1 + n2);
    return 0;
}
```
The time complexity for the naive approach is O((m+n)log(m+n)), because of element insertion and sorting after that.
The second method is much better and has the time complexity. It actually uses the approach used for merge sort.
> * Create an array `arr3[]` of size `n1+n2`.
> * Simultaneously traverse `arr1[]` and `arr2[]`.
> 	* Pick smaller of current elements in `arr1[]` and `arr2[]`, copy the smaller element to next position in `arr3[]` and move ahead in `arr3[]` and the array whose element is picked.
> * If there are remaining elements in `arr1[]` or `arr2[]`, copy them also in `arr3[]`.

```cpp
void merge(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
    int i = 0, j = 0, k = 0;
    // start from the start of both the arrays
    while (i < n1 && j < n2)
    {
        // if an element in arr1 is smaller than the one in arr2
        if (arr1[i] < arr2[j])
            // put it in arr3, and then increment the pointer of arr3 and arr1
            arr3[k++] = arr1[i++];
        // else put it in arr3, and then increment the pointer of arr3 and arr2
        else
            arr3[k++] = arr2[j++];
    }
    // if one of the array is complete but there are remaining elements then push all into arr3
    while (i < n1)
        arr3[k++] = arr1[i++];
    // do the same for the second array
    while (j < n2)
        arr3[k++] = arr2[j++];
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    // initialize arrays that are to be merged
    int arr1[] = {1, 3, 5, 7}, arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]), n2 = sizeof(arr2) / sizeof(arr1[0]);
    // initialize final array of cumulative size
    int arr3[n1 + n2];
    // call merge function
    merge(arr1, arr2, n1, n2, arr3);
    printArray(arr3, n1 + n2);
    return 0;
}
```
This method has the time complexity of O(n1+n2) and also the same space complexity.
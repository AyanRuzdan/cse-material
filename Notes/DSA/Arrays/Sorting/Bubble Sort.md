# Bubble Sort
**Time Complexity: O(n<sup>2</sup>)**
Bubble sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst case time complexity is quite high.
## Approach
```cpp
//let the array be
{5,1,4,2,8}
//after FIRST PASS we shift 5 to its position by repeated swapping
{1,5,4,2,8} //swapped 1 & 5
{1,4,5,2,8} //swapped 4 & 5
{1,4,2,5,8} //swapped 2 & 5
{1,4,2,5,8} //no swap required
//SECOND PASS
{1,4,2,5,8} //1 & 4 are okay
{1,2,4,5,8} //swapped 2 & 4
{1,2,4,5,8} //4 & 5 are okay
{1,2,4,5,8} //5 & 8 are fine
//THIRD PASS
{1,2,4,5,8} //1 & 2 are fine
{1,2,4,5,8} //2 & 4 are fine
{1,2,4,5,8} //4 & 5 are fine
{1,2,4,5,8} //5 & 8 are fine
```
---
## Code
```cpp
#include <bits/stdc++.h>
using namespace std;

// function to bubble sort the array
void bubbleSort(int arr[], int size)
{
    int i, j;
    // outer loop
    for (i = 0; i < size; i++)
    {
        // inner loop
        for (j = 0; j < size - i - 1; j++)
        {
            // if elemet is smaller that the next one
            if (arr[j] > arr[j + 1])
            {
                // then swap the elements
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

// driver function
int main()
{
    // initialise array
    int arr[] = {7, 8, 3, 9, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n); // call bubble sort
    cout << "Sorted array is : ";
    printArray(arr, n);
}
```
# Binary Search
**Time Complexity: $O(logn)$**
Binary Search is a searching algorithm used in a sorted/monotonic array by repeatedly dividing the search interval in half.
Basics steps to perform Binary Search:
* Begin with the mid element of the whole array as a search key.
* If the value of the search key is equal to the item then return the index of the search key.
* Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
* Otherwise narrow it to the upper half.
* Repeatedly check from the second point until the value is found or the interval is empty.
> **There are two approaches for Binary Search: Iterative and Recursive**

## **Iterative (Simple) Approach**:
```cpp
#include <bits/stdc++.h>
using namespace std;
// binary Search function
int binarySearch(int arr[], int left, int right, int x)
{
    // condition for convergence
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) // element is in the middle and is found
            return x;
        if (arr[mid] < x)   // element is on the right side
            left = mid + 1; // search space shifts to the right
        else
            right = mid - 1; // search space shifts to the left
    }
    return -1; // element not found
}

// driver function
int main()
{
    // initialise array
    int arr[] = {1, 2, 3, 5, 7, 9, 10, 11, 12};
    int x = 2; // element to search
    int n = sizeof(arr) / sizeof(arr[0]);
    // call function to search
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
    {
        cout << "Element is not present in the array.";
    }
    else
    {
        cout << "The element is present at the index " << result;
    }
}
```
---
## **Recursive Approach**:
```cpp
#include <bits/stdc++.h>
using namespace std;
// function for binary search
int binarySearch(int arr[], int left, int right, int x)
{
    // as long as pointers do not cross each other
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;   // element is found in the middle of the array
        if (arr[mid] > x) // element is in the left side of the search space
            return binarySearch(arr, left, mid - 1, x);
        // else element is in the right side of the search space
        return binarySearch(arr, mid + 1, right, x);
    }
    // element not found
    return -1;
}

// driver function
int main()
{
    // initialise array
    int arr[] = {1, 2, 3, 5, 7, 9, 10, 11, 12};
    int x = 2; // element to search for
    int n = sizeof(arr) / sizeof(arr[0]);
    // call function binarySearch to search for x
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
    {
        cout << "Element is not present in the array.";
    }
    else
    {
        cout << "The element is present at the index " << result;
    }
}
```
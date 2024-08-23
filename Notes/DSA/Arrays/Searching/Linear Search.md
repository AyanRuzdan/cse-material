# Linear Search
**Time Complexity: $O(n)$**
It is defined as a sequential search algorithm that starts at one end and goes through each element of a list until the desired element is found, otherwise the search continues till the end of the data set. It is the easiest searching algorithm.
```cpp
#include <bits/stdc++.h>
using namespace std;
int search(int arr[], int size, int key)
{
    int i;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 9, 7, 5, 6};
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, n, x);
    if (result == -1)
    {
        cout << "Element not found in the array.";
    }
    else
    {
        cout << "Element is present at index: " << result;
    }
}
```
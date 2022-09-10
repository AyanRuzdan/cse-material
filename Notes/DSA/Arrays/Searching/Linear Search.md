# Linear Search
## Time Complexity: O(n)
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
```
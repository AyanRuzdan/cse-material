# Insertion Sort
**Time Complexity: O(n<sup>2</sup>)**
Insertion sort is a sorting algorithm that works similar to the way we sort playing cards in our hands. The array is virtually split into a sorted and unsorted part. Values from the unsorted part are picked up and placed at the correct position in the sorted part.
```cpp
{12, 11, 13, 5, 6} //initial position
{12, 11, 13, 5, 6} //12 and 11 are not in correct order and will be swapped
{11, 12, 13, 5, 6} //11 and 12 are now swapped and sorted
{11, 12, 13, 5, 6} //12 and 13 are now compared
{11, 12, 13, 5, 6} //12 and 13 are in sorted position and need not be swapped
{11, 12, 5, 13, 6} //12 and 5 are not sorted and will be swapped
{11, 5, 12, 13, 6} //11 and 5 are not sorted and will be swapped
{5, 11, 12, 13, 6} //13 and 6 are not sorted and will be swapped
{5, 11, 12, 6, 13} //12 and 6 are not sorted and will be swapped
{5, 11, 6, 12, 13} //11 and 6 are not sorted and will be swapped
{5, 6, 11, 12, 13} //5 and 6 are already sorted and need not be sorted
```
## Approach
* Iterate from `arr[1]` to `arr[N]` over the array.
* Compare the current element to its predecessor.
* If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.

```cpp
#include<bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[], int n)
{
	int i, j, key;
	for(i=1;i<n;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}
void printArray(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	insertionSort(arr, n);
	printArray(arr, n);
}
```
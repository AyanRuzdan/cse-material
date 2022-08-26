# Insertion Sort
**Time Complexity: O(n2)**
Insertion sort is a sorting algorithm that works similar to the way we sort playing cards in our hands. The array is virtually split into a sorted and unsorted part. Values from the unsorted part are pickec up and placed at the correct position in the sorted part.
```cpp
{12, 11, 13, 5, 6} //initial position
{12, 11, 13, 5, 6} //12 and 11 are not in correct order and will be swapped
{11, 12, 13, 5, 6} //11 and 12 are now swapped and sorted
{11, 12, 13, 5, 6} //12 and 13 are now compared
{11, 12, 13, 5, 6} //12 and 13 are in sorted position and need not be swapped
{11, 5, 12, 13, 6} 
{5, 11, 12, 13, 6}
{5, 11, 12, 13, 6}
{5, 11, 12, 6, 13}
{5, 11, 6, 12, 13}
{5, 6, 11, 12, 13}
```
## Approach
* Iterate from `arr[1]` to `arr[N]` over the array.
* Compare the current element to its predecessor.
* If the key element is smaller than its predecessor, comapre it to the elements before. Move the greater elements one position up to make space for the swapped element.
# Heap Sort
**Time Complexity: $O(nlogn)$**
Heap sort uses the heap data structure to keep the min/max element at the top of the heap, which is then swapped with the last element of the heap in the list form. Then the heap size is reduced by one and then the heap is heapified again. Iteratively the top element is put in the sorted portion of the list, and the unsorted list is heapified.
## Approach
```cpp
// let the array be
{10,5,4,9,11,3,6}
// after heapifying the array becomes
{11,10,6,9,5,3,4}
// first and last element are swapped
{4,10,6,9,5,3,11}
// call heapify again
{10,9,6,4,5,3,11}
// swap again
{3,9,6,4,5,10,11}
// heapify
{9,5,6,4,3,10,11}
// swap
{3,5,6,4,9,10,11}
// heapify
{6,5,3,4,9,10,11}
// swap
{4,5,3,6,9,10,11}
// heapify
{5,4,3,6,9,10,11}
// swap
{3,4,5,6,9,10,11}
// atp heapifying and swapping will give the sorted results anyway, so the final sorted list will look like
{3,4,5,6,9,10,11}
```
## Code
```cpp
void heapify(vector<int> &arr, int n, int i)
{
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[parent])
        parent = left;
    if (right < n && arr[right] > arr[parent])
        parent = right;
    if (parent != i)
    {
        swap(arr[i], arr[parent]);
        heapify(arr, n, parent);
    }
}
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){

}
```

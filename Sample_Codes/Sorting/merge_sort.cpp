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
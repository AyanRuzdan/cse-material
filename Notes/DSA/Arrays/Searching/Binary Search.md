# Binary Search
**Time Complexity: O(logn)**
Binary Search is a searching algorithm used in a sorted/monotonic array by repeatedly dividing the search interval in half.
Basics steps to perform Binary Search:
* Begin with the mid element of the whole array as a search key.
* If the value of the search key is equal to the item then return the index of the search key.
* Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
* Otherwise narrow it to the upper half.
* Repeatedly check from the second point until the value is found or the interval is empty.
> **There are two approaches for Binary Search: Iterative and Recursive**

**Iterative (Simple) Approach**

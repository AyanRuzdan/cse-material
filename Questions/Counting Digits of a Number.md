## Iterative Solution
**Approach:** Keep on dividing the number by 10 as long as the number is not zero. Increment counter in every iteration.
**Special Case:** If the number itself is 0 then print 1.
**Time Complexity:** O(log n)
**Space Complexity:** 0(1)
Code:
```cpp
int digitCount(int n)
{
    int count = 0;
    if (n == 0)
        return 1;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
```
## Recursive Solution
**Approach:** If number by 10 equals 0 then return 1, else return 1 + fun(n/10)
**Time Complexity:** 0(log n)
**Space Complexity** 0(log n), due to function call stack
Code:
```cpp
int digitCountRecur(int n)
{
    if (n / 10 == 0)
        return 1;
    return (1 + digitCountRecur(n / 10));
}
```
> **Note:** Special case is already covered in the base case of the recursion.
## Question Statement
Implement [pow(x, n)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` (i.e., $x^n$).
## Examples
**Example 1:**
>Input: x = 2.00000, n = 10
>Output: 1024.00000

**Example 2:**
>Input: x = 2.10000, n = 3
Output: 9.26100

**Example 3:**
>Input: x = 2.00000, n = -2
>Output: 0.25000
>Explanation: 2-2 = 1/22 = 1/4 = 0.25
## Approach
Using a recursive approach, the power of a number can be calculated by halving the power until it reaches a base case, meanwhile handling the case of odd and even powers. In C++ the integer limit sometimes causes issues, hence the conversion to `long long` is necessary to deal with larger powers and bases.
## Code
```cpp
double myPow(double a, int b)
{
    long long exp = b;
    if (exp < 0)
    {
        a = 1 / a;
        exp = -exp;
    }
    if (exp == 0)
        return 1;
    if (exp == 1)
        return a;
    if (exp % 2)
        return a * myPow(a, exp - 1);
    else
        return myPow(a * a, exp / 2);
}
```
Tags: [[Recursion]], [[Math]]
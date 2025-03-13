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
Using a recursive approach, the power of a number can be calculated by halving the power until it reaches a base case, meanwhile handling the case of odd and even powers. In CPP the integer limit sometimes causes issues, hence the conversion to `long double` is necessary to deal with larger powers and bases.
## Code
```cpp
class Solution {
public:
    long double helper(double x, long long n) {
        if (n == 0) {
            return 1.0; //  do not return x but 1 as x^0 = 1 not x
        }
        long double ans = helper(x, n / 2); // store x^(n/2) into a new variable
        ans = ans * ans; // square the variable
        if (n % 2) // if n is odd, an extra time the number is to be multiplied
            ans = ans * x;
        return ans; // otherwise return the squared value
    }
    double myPow(double x, int n) {
        long long val;
        if (n < 0)
            val = -1.0 * n; // if there is a negative power
        long double ans = helper(x, val); // call helper power function
        if (n < 0) { // if power is negative, move number into reciprocal
            ans = 1.0 / ans;
        }
        return ans;
    }
};
```
Tags: [[Recursion]], [[Math]]
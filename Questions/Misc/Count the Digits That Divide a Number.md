## Question Statement
Given a positive integer **`n`**, count the number of digits in `n` that divide `n` evenly (i.e., without leaving a remainder). Return the total number of such digits.

> A digit `d` of `n` divides `n` evenly if the remainder when `n` is divided by `d` is 0 (`n % d == 0`).  
> Digits of `n` should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.

## Examples
>Example 1:
>Input: 12
>Output: 2
>Explanation: 1 and 2 both leave remainder 0 when dividing 12, hence the answer is 2

>Example 2:
>Input: 2446
>Output: 1
>Explanation: Out of 2, 4, and 6, only 2 divides 2446 completely, hence the answer is 1

>Example 3:
>Input: 33
>Output: 2
>Explanation: Both 3 divide 33 completely, hence the answer is 2

## Approach
Have a list that contains all the digits of the given number, as it will be used to iterate over for the division process. It is necessary to know the fact that we cannot use a set, as we need to check the division for repeated digits, as in the case for 33 where the division is to be checked for both 3s.
## Code
```cpp
int evenlyDivides(int n)
{
    // code here
    int res = 0;
    vector<int> v;
    int divider = n;
    while (n != 0)
    {
        int temp = n % 10;
        if (temp != 0)
            v.push_back(temp);
        n /= 10;
    }
    for (auto item : v)
    {
        if (divider % item == 0)
            res++;
    }
    return res;
}
```
Tags: [[Math]]
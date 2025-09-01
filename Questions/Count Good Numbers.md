```cpp
const int MOD = 1e9 + 7;

int qmul(long long x, long long y)
{
    if (y == 0)
        return 1;
    long long half = qmul(x, y / 2); // stores the input
    // does not calculate twice while squaring
    long long res = (half * half) % MOD;
    if (y % 2 == 1)
        res = (res * x) % MOD;
    return (int)res;
}

int countGoodNumbers(long long n)
{
    return (long long)qmul(5, (n + 1) / 2) * qmul(4, n / 2) % MOD;
}
```
Tags: [[Recursion]], [[Math]]
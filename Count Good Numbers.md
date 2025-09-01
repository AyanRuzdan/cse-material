```cpp
const int MOD = 1e9 + 7;
auto qmul(int x, long long y)
{
    int prod = 1;
    int mul = x;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            prod = (long long)prod * mul % MOD;
        }
        mul = (long long)mul * mul % MOD;
        y /= 2;
    }
    return prod;
}
int countGoodNumbers(long long n)
{
    return (long long)qmul(5, (n + 1) / 2) * qmul(4, n / 2) % MOD;
}
```
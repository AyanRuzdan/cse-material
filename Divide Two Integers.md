```cpp
int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    bool neg = (dividend < 0) ^ (divisor < 0);
    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);
    long long res = 0;
    while (a >= b)
    {
        long long temp = b, multiple = 1;
        while (a >= (temp << 1))
        {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        res += multiple;
    }
    if (neg)
        res = -res;
    if (res > INT_MAX)
        return INT_MAX;
    if (res < INT_MIN)
        return INT_MIN;
    return (int)res;
}
```

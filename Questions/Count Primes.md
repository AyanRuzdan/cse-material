```cpp
int countPrimes(int n)
{
    if (n <= 2)
        return 0;
    vector<int> sieve(n, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i * i < n; i++)
    {
        if (sieve[i] == 1)
        {
            for (int j = i * i; j < n; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    return accumulate(sieve.begin(), sieve.end(), 0);
}
```
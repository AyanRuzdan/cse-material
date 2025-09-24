```cpp
string fractionToDecimal(int64_t n, int64_t d)
{
    string res;
    if (n == 0)
        return "0";
    if (n < 0 ^ d < 0)
        res += '-';
    n = abs(n), d = abs(d);
    res += to_string(n / d);
    if (n % d == 0)
        return res;
    res += '.';
    map<int, int> mp;
    for (int64_t r = n % d; r; r %= d)
    {
        if (mp.count(r) > 0)
        {
            res.insert(mp[r], 1,
                       '('); // insert bracket 1 time at map[r] index
            res += ')';
            break; // end of recurring
        }
        mp[r] = res.size(); // update index for new remainder
        r *= 10;            // r %= d and previous if condition will take care
                            // eventually
        res += to_string(r / d);
    }
    return res;
}
```
Tags: [[Strings]], [[Math]]
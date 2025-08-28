```cpp
long atoi(string s, int sign, int i, long res)
{
    if (sign * res >= INT_MAX)
        return INT_MAX;
    if (sign * res <= INT_MIN)
        return INT_MIN;
    if (i >= s.size() || s[i] < '0' || s[i] > '9')
        return sign * res;
    res = atoi(s, sign, i + 1, res * 10 + (s[i] - '0'));
    return res;
}
int myAtoi(string s)
{
    int n = s.size();
    int i = 0;
    int sign = 1;
    while (i < n && s[i] == ' ')
        i++; // skip front whitespace
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
        i++;
    return atoi(s, sign, i, 0);
}
```

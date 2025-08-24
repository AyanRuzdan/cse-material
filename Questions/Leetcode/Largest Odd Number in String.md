```cpp
string largestOddNumber(string s)
{
    int idx = s.size();
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if ((s[i] - '0') % 2 == 0)
            continue;
        else
        {
            idx = i;
            break;
        }
    }
    return idx == s.size() ? "" : s.substr(0, idx + 1);
}
```

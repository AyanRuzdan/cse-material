```cpp
string removeKdigits(string num, int k)
{
    if (num.length() == k)
        return "0";
    string ans;
    vector<char> stack;
    for (char c : num)
    {
        while (k > 0 && !stack.empty() && stack.back() > c)
        {
            stack.pop_back();
            k--;
        }
        stack.push_back(c);
    }
    while (k-- > 0)
    {
        stack.pop_back();
    }
    for (char c : stack)
    {
        if (c == '0' && ans.empty())
            continue;
        ans.push_back(c);
    }
    return ans.empty() ? "0" : ans;
}
```
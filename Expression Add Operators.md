```cpp
void solve(const string &num, int start, long long curr, long long last,
           string &temp, vector<string> &res, long long target)
{
    int n = (int)num.size();
    if (start == n)
    {
        if (curr == target)
        {
            res.push_back(temp);
            return;
        }
    }
    for (int end = start; end < n; end++)
    {
        if (end > start && num[start] == '0')
            break;
        string sub = num.substr(start, end - start + 1);
        long long val = stoll(sub);
        int oldLen = temp.size();
        if (start == 0)
        {
            temp += sub;
            solve(num, end + 1, val, val, temp, res, target);
            temp.resize(oldLen);
        }
        else
        {
            temp += '+';
            temp += sub;
            solve(num, end + 1, curr + val, val, temp, res, target);
            temp.resize(oldLen);

            temp += '-';
            temp += sub;
            solve(num, end + 1, curr - val, -val, temp, res, target);
            temp.resize(oldLen);

            temp += '*';
            temp += sub;
            solve(num, end + 1, curr - last + last * val, last * val, temp,
                  res, target);
            temp.resize(oldLen);
        }
    }
}
vector<string> addOperators(string num, int target)
{
    vector<string> res;
    if (num.empty())
        return {};
    string temp;
    solve(num, 0, 0LL, 0LL, temp, res, (long long)target);
    return res;
}
```
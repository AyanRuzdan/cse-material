```cpp
void solve(string s, vector<vector<string>> &res, vector<string> &temp,
           int start)
{
    if (start == s.size())
    {
        res.push_back(temp);
        return;
    }
    for (int end = start; end < s.size(); end++)
    {
        int ee = end, st = start;
        bool flag = true;
        while (st <= ee)
        {
            if (s[st++] != s[ee--])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            temp.push_back(s.substr(start, end - start + 1));
            solve(s, res, temp, end + 1);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> temp;
    solve(s, res, temp, 0);
    return res;
}
```
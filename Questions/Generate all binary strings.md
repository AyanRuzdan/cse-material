```cpp
void solve(vector<string> &res, string temp, int n, int i)
{
    if (i == n)
    {
        res.push_back(temp);
        return;
    }
    temp.push_back('0');
    solve(res, temp, n, i + 1);
    temp.pop_back();
    temp.push_back('1');
    solve(res, temp, n, i + 1);
}
```
Tags: [[Recursion]], [[Permutation]]
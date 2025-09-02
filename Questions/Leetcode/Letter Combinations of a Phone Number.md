```cpp
void dfs(vector<string> &res, string &temp, int idx, string mp[],
         string digits)
{
    if (idx == digits.size())
    {
        res.push_back(temp);
        return;
    }
    int num = digits[idx] - '0';
    string runner = mp[num];
    for (int i = 0; i < runner.size(); i++)
    {
        temp.push_back(runner[i]);
        dfs(res, temp, idx + 1, mp, digits);
        temp.pop_back();
    }
}
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};
    vector<string> res;
    string temp = "";
    string mp[] = {"", "", "abc", "def", "ghi",
                   "jkl", "mno", "pqrs", "tuv", "wxyz"};
    dfs(res, temp, 0, mp, digits);
    return res;
}
```
Tags: [[Recursion]], [[Maps]], [[Strings]], [[Backtracking]]
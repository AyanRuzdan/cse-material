```cpp
string frequencySort(string s)
{
    string temp = "";
    map<int, int> mp;
    vector<pair<int, int>> vp;
    for (auto c : s)
    {
        mp[c]++;
    }
    for (auto item : mp)
    {
        vp.push_back({item.second, item.first});
    }
    sort(vp.rbegin(), vp.rend());
    for (auto p : vp)
    {
        while (p.first--)
        {
            temp.push_back(char(p.second));
        }
    }
    return temp;
}
```

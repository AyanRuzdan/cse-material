```cpp
string reverseWords(string s)
{
    stack<string> st;
    string res = "";
    int i = 0, j = 0, n = s.size();
    while (j < n)
    {
        while (s[i] == ' ' && s[j] == ' ' && j < n)
        {
            j++;
            i = j;
        }
        while (s[j] != ' ' && j < n)
            j++;
        if (i < j)
            st.push(s.substr(i, j - i));
        i = j;
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
        if (!st.empty())
            res += " ";
    }
    return res;
}
```
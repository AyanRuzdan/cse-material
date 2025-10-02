```cpp
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '-' || c == '+')
    {
        return 1;
    }
    return -1;
}
string infixToPostfix(string &s)
{
    // code here
    string res;
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isalpha(c) || isdigit(c))
            res += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && (prec(c) < prec(st.top()) || (prec(c) == prec(st.top()) && c != '^')))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}
```
Tags: [[Stacks]]

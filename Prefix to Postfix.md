```cpp
string pretopost(string expr)
{
    stack<string> st;
    for (int i = expr.size() - 1; i >= 0; i--)
    {
        if (!isalpha(expr[i]))
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push(s1 + s2 + expr[i]);
        }
        else
        {
            string temp{expr[i]};
            st.push(temp);
        }
    }
    return st.top();
}
```
Tags: [[Stacks]]
```cpp
string pre_to_in(string expr)
{
    stack<string> st;
    for (int i = expr.size() - 1; i >= 0; i--)
    {
        if (isalpha(expr[i]))
        {
            string temp{expr[i]};
            st.push(temp);
        }
        else
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            st.push('(' + top1 + expr[i] + top2 + ')');
        }
    }
    return st.top();
}
```
Tags: [[Stacks]]
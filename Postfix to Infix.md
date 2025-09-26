```cpp
string posttoin(string exp)
{
    stack<string> st;
    for (int i = 0; i < exp.size(); i++)
    {
        if (!isalpha(exp[i]))
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push('(' + s2 + exp[i] + s1 + ')');
        }
        else
        {
            string temp{exp[i]};
            st.push(temp);
        }
    }
    return st.top();
}
```
Tags: [[Stacks]]
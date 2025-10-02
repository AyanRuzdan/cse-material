```cpp
string posttopre(string post_exp)
{
    stack<string> st;
    for (int i = 0; i < post_exp.size(); i++)
    {
        if (!isalpha(post_exp[i]))
        {
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            st.push(post_exp[i] + s2 + s1);
        }
        else
        {
            string temp{post_exp[i]};
            st.push(temp);
        }
    }
    return st.top();
}
```
Tags: [[Stacks]]
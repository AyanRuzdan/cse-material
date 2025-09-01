```cpp
void insertEle(stack<int> &st, int q)
{
    if (st.empty())
    {
        st.push(q);
        return;
    }
    int temp = st.top();
    st.pop();
    insertEle(st, q);
    st.push(temp);
}
void reverse(stack<int> &st)
{
    if (st.empty())
        return;
    int q = st.top();
    st.pop();
    reverse(st);
    insertEle(st, q);
}
```
Tags: [[Stacks]], [[Recursion]]
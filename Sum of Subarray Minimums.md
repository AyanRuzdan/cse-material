```cpp
vector<int> NSE(vector<int> &arr)
{
    vector<int> nse(arr.size());
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        nse[i] = !st.empty() ? st.top() : arr.size();
        st.push(i);
    }
    return nse;
}
vector<int> PSE(vector<int> &arr)
{
    vector<int> pse(arr.size());
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        pse[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return pse;
}
int sumSubarrayMins(vector<int> &arr)
{
    long long MOD = 1e9 + 7;
    int res = 0;
    vector<int> nse = NSE(arr);
    vector<int> pse = PSE(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        int l = i - pse[i];
        int r = nse[i] - i;
        long long freq = l * r * 1LL;
        int val = (freq * arr[i] * 1LL) % MOD;
        res = (res + val) % MOD;
    }
    return res;
}
```
Tags: [[Stacks]]
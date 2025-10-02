```cpp
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    int idx = 2 * n - 1;
    vector<int> res(n, -1);
    for (int i = idx; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push(nums[i % n]);
            // i is the bigger number
        }
        else
        {
            if (st.top() > nums[i % n])
            {
                res[i % n] = st.top();
                st.push(nums[i % n]);
            }
            else
            {
                while (!st.empty() && st.top() <= nums[i % n])
                {
                    st.pop();
                }
                if (!st.empty())
                    res[i % n] = st.top();
                else
                    res[i % n] = -1;
                st.push(nums[i % n]);
            }
        }
    }
    return res;
}
```
Tags: [[Stacks]]
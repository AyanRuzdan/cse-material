```cpp
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        if (st.count(nums[i]) != 0)
            return true;
        st.insert(nums[i]);
        if (st.size() > k)
            st.erase(nums[i - k]);
    }
    return false;
}
```
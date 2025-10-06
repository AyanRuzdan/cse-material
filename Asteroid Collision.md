```cpp
vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> st;
    for (auto item : asteroids)
    {
        if (item > 0)
            st.push_back(item);
        else
        {
            while (!st.empty() && st.back() > 0 && st.back() < abs(item))
                st.pop_back();
            if (!st.empty() && st.back() == abs(item))
            {
                st.pop_back();
            }
            else if (st.empty() || st.back() < 0)
            {
                st.push_back(item);
            }
        }
    }
    return st;
}
```
Tags: [[Stacks]]
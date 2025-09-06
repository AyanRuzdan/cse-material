```cpp
vector<int> singleNumber(vector<int> &nums)
{
    long xory = 0;
    for (auto item : nums)
        xory = xory ^ item;
    int temp1 = xory & (xory - 1);
    int temp2 = temp1 ^ xory;
    int b1 = 0, b2 = 0;
    for (auto item : nums)
    {
        if (item & temp2)
            b1 = b1 ^ item;
        else
            b2 = b2 ^ item;
    }
    return {b1, b2};
}
```
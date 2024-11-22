## Question Statement
Given an array of integers `temperatures` represents the daily temperatures, return _an array_ `answer` _such that_ `answer[i]` _is the number of days you have to wait after the_ `ith` _day to get a warmer temperature_. If there is no future day for which this is possible, keep `answer[i] == 0` instead.
## Example
**Example 1:**
>**Input:** temperatures = [73,74,75,71,69,72,76,73]
>**Output:** [1,1,4,2,1,1,0,0]

**Example 2:**
>**Input:** temperatures = [30,40,50,60]
>**Output:** [1,1,1,0]

**Example 3:**
>**Input:** temperatures = [30,60,90]
>**Output:** [1,1,0]

## Approach
For this problem we use a monotonically decreasing stack. We need to traverse the temperature array, and maintain a stack of temp and corresponding index. In the stack if the element in the array is greater than the top of the stack, then that element is processed/popped and it's index and current array index is subtracted and added to the resultant array. A while loop is implemented to process all temperatures smaller than the current temperature, and in order to make sure that we have only smaller temperatures in the stock, we maintain it so that it is always a monotonically decreasing stack. 
## Code
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;
        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!st.empty() && t > st.top().first) {
                auto pair = st.top();
                st.pop();
                res[pair.second] = i - pair.second;
            }
            st.push({t, i});
        }
        return res;
    }
};

```

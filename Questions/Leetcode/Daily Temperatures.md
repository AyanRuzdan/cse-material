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

## Question Statement
Given an integer array `nums` and an integer `k`, return _the_ `k` _most frequent elements_. You may return the answer in **any order**.

## Examples
**Example 1:**
**Input:** nums = [1,1,1,2,2,3], k = 2
**Output:** [1,2]

**Example 2:**
**Input:** nums = [1], k = 1
**Output:** [1]

## Approach
Make a hashmap to store the frequencies of all the elements. Then perform bucket sort and store the elements according to frequency. Finally start from the end of the bucket and insert values from the bucket in the resultant list.

## Code
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    int n = nums.size(); // need not make a variable
    unordered_map<int, int> m; // make map for mapping frequencies
    for(int i=0;i<n;i++)
        m[nums[i]]++;
    vector<vector<int>> b(n+1); // make bucket
    for(auto i=m.begin(); i!=m.end();i++) // dont use less than for condition check
        b[i->second].push_back(i->first);
    vector<int> res; //make final result vector
    for(int i=n;i>=0;i--)
    {
        if(res.size() >= k) // search complete
        break;
        if(!b.empty())
        res.insert(res.end(), b[i].begin(), b[i].end()); // insert bucket value in result
    }
    return res;
    }
};
```
Tags: [[Arrays]], [[Sorting]], [[Maps]]
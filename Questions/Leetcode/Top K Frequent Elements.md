## Question Statement
Given an integer array `nums` and an integer `k`, return _the_ `k` _most frequent elements_. You may return the answer in **any order**.

## Examples
**Example 1:**
**Input:** nums = [1,1,1,2,2,3], k = 2
**Output:** [1,2]

**Example 2:**
**Input:** nums = [1], k = 1
**Output:** [1]

## Approach 1
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
## Approach 2
In this approach we can make use of a max-heap to find the elements with the largest frequency. First make a frequency map using an unordered or ordered map. Then push pair of frequency and element into the heap. Then for `k` times, fetch the top of the heap. Push the answer into a resultant vector and output accordingly. 
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // map to contain frequency of elements
        for(auto item:nums) mp[item]++; // find frequency
        priority_queue<pair<int, int>> pq; // max heap to contain frequency pair
        for(auto item:mp){
            pq.push({item.second, item.first});
            // insert frequency pair in the heap, frequency first
        }
        vector<int> res; // resultant vector
        while(k--){ // need to find top k values only
            res.push_back(pq.top().second);
            // insert the element from the top of the heap's 
            // pair into the resultant vector
            pq.pop(); // move on to the next most frequent element
        }
        return res; // return resultant vector
    }
};

```

Tags: [[Arrays]], [[Sorting]], [[Maps]], [[Heaps]]
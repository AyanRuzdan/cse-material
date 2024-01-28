## Question Statement
Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

## Examples
**Example 1:**
**Input:** strs = {"eat","tea","tan","ate","nat","bat"}
**Output:** {{"bat"}, {"nat","tan"}, {"ate","eat","tea"}} 

**Example 2:**
**Input:** strs = {""}
**Output:** {{""}}

**Example 3:**
**Input:** strs = {"a"}
**Output:** {{"a"}}

## Approach
Make a map of string and list of strings. Pick each string, sort it and add the given string to the key of the sorted string. Then in order to return the answer make a list of list, and add the values from the map.

## Code
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string s:strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto item:mp){
            ans.push_back(item.second);
        }
        return ans;
    }
};
```
Tags: [[Maps]], [[Strings]]
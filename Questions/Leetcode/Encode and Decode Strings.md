## Question Statement
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.
Please implement `encode` and `decode`.
## Example
**Example 1:**
>**Input:** \["neet","code","love","you"]
>**Output:** \["neet","code","love","you"]

**Example 2:**
>**Input:** \["we","say",":","yes"]
>**Output:** \["we","say",":","yes"]

## Approach
### Encode
The given vector of strings can be encoded in numerous ways, but as we need to decode it later on, we need to follow specific encoding practices. For encoding we can append the string with the length of the string and special symbol as a separator between the length of the string and the string itself. All of this can be added into one single string that will be later used for decoding.
### Decode
We now have one fully encoded string and we need to decode it. In the outer scope we need to have an index variable that will traverse the string and process it. Inside the loop a scoped index called `jindex` can be used. Initially using `jindex` we get the length of the word, which is separated by `#`. Then we follow step by step. After getting the length of the word we move `index` to the first letter of the word and `jindex` to the next *number*/*length of word*. Then we extract the substring using `index` and `length` and push it into the resultant vector. Then we move the `index` to `jindex` and continue with the next encoded word.
## Code
```cpp
class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res;
        for (auto st : strs)
        {
            res += to_string(st.size()) + "#" + st;
        }
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int index = 0;
        while (index < s.size())
        {
            int jindex = index;
            while (s[jindex] != '#')
            {
                jindex++;
            }
            int length = stoi(s.substr(index, jindex - index));
            index = jindex + 1;
            jindex = index + length;
            res.push_back(s.substr(index, length));
            index = jindex;
        }
        return res;
    }
};
```
Tags: [[Strings]], [[Two Pointers]]
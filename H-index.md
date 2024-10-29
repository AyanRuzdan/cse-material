## Question Statement

Given an array of integers `citations` where `citations[i]` is the number of citations a researcher received for their `ith` paper, return _the researcher's h-index_.
According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): The h-index is defined as the maximum value of `h` such that the given researcher has published at least `h` papers that have each been cited at least `h` times.

## Examples

**Example 1:**
>**Input:** citations = [3,0,6,1,5]
>**Output:** 3
>**Explanation:** [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
>Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

**Example 2:**
>**Input:** citations = [1,3,1]
>**Output:** 1

## Approach
Use counting sort to find which paper has been cited how many times. Then perform a prefix sum on the count buckets to find accumulated citations for each paper. Iterate from the back of the prefix sum array and find which paper exceeds citation count, return that index.

## Code

```cpp
int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int num : citations) {
            count[min(num, n)]++;
        }
        for (int i = count.size() - 1; i > 0; i--) {
            count[i - 1] += count[i];
        }
        for (int i = count.size() - 1; i > 0; i--) {
            if (i <= count[i]) {
                return i;
            }
        }
        return 0;
    }
```

Tags: [[Top Interview 150]], [[Counting Sort]], [[Prefix Sum]], [[Arrays]]
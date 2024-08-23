## Question Statement

Given an integer array `nums`, return an array `output` where `output[i]` is the product of all the elements of `nums` except `nums[i]`.

## Examples

**Example 1:**
> **Input:** nums = [1,2,3,4]
> **Output:** [24,12,8,6]

## Approach 1
Brute force Approach: Take product of all elements and then divide by ith element.

## Code

```
```

## Approach 2(using Prefix Product and Suffix Product)
Without Division in O(n) : make the prefix and suffix product arrays and add a 1 before the prefix array and at the end of Suffix array. Remove the last element of Pre and 1st element of Suffix.
Pre: [1,2,3,4] ==> [1,2,6,24] ==> [1,1,2,6]
Suffix: [1,2,3,4] ==> [24,24,12,4] ==> [24,12,4,1]
Now to get the desired output multiply the corresponding elements of pre and suff.

## Code

```Python3

```

Tags: [[Sets]], [[Arrays]]

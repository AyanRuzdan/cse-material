## Question Statement

Given an integer array `nums`, return _an array_ `answer` _such that_ `answer[i]` _is equal to the product of all the elements of_ `nums` _except_ `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

## Examples

**Example 1:**

> **Input:** nums = [1,2,3,4]
> **Output:** [24,12,8,6]

**Example 2:**

> **Input:** nums = [-1,1,0,-3,3]
> **Output:** [0,0,9,0,0]

## Approach 1
**Brute force Approach:** Take product of all elements and then divide by $i^{th}$ element.

## Code

```cpp
vector<int> productOfArrayExceptSelf(vector<int> &v)
{
    auto prod = 1;
    for (int i = 0; i < v.size(); i++)
        prod *= v[i];
    for (int i = 0; i < v.size(); i++)
        v[i] = prod / v[i];
    return v;
}
```

## Approach 2
### (Using Prefix Product and Suffix Product)
Without Division in $O(n)$: Make the prefix and suffix product arrays and add a 1 before the *prefix* array and at the end of *suffix* array. Remove the last element of *pre* and 1st element of *suffix*.
Pre:
```cpp
{1,2,3,4} // original array
{1,2,3,4} // multiply 1 to 2
{1,2,6,4} // multiply 2 to 3
{1,2,6,24} // multiply 6 to 4
{1,1,2,6} // modified prefix product array by adding 1 to beginning and removing last product
```
Suffix:
```cpp
{1,2,3,4} // original array
{1,2,12,4} // multiply 4 to 3
{1,24,12,4} // multiply 12 to 2 and result 24
{24,24,12,4} // multiply 24 to 1 and result 24
{24,12,4,1} // modified suffix product array by adding 1 to the end and removing first product
```
Now to get the desired output multiply the corresponding elements of *prefix* and *suffix* product arrays.
> 	 {01,01,2,6}
>    $\times$   {24,12,4,1}
>    =    {24,12,8,6}
## Code
Python:
```python
nums = [1,2,3,4]
n=len(nums)
pre=[1]*n
suff=[1]*n
for i in range(n-1):
    pre[i+1]=pre[i]*nums[i]
    suff[n-1-(i+1)]=suff[n-1-i]*nums[n-1-i]
arr=[]    
for i in range(n):
    arr.append(pre[i]*suff[i])
print(arr)

```
CPP:
```cpp
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> start(n);      
        vector<int> end(n);
        start[0] = 1; end[0] = 1;
        for(int i = 1; i < n; i++){
            start[i] = start[i-1]*nums[i-1];
            end[i] = end[i-1] * nums[n-i];
        }      
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[i] = start[i] * end[n-i-1];
        }
        return res;
    }
```
Tags:  [[Arrays]]

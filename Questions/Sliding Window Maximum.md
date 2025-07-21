## Question Statement
You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.
Return _the max sliding window_.
## Examples
>**Example 1:**
>**Input:** nums = [1,3,-1,-3,5,3,6,7], k = 3
>**Output:** [3,3,5,5,6,7]
>**Explanation:** 
>Window position                Max
>\[1  3  -1] -3  5  3  6  7      **3**
>1 \[3  -1  -3] 5  3  6  7       **3**
>1  3 \[-1  -3  5] 3  6  7       **5**
>1  3  -1 \[-3  5  3] 6  7       **5**
>1  3  -1  -3 \[5  3  6] 7       **6**
>1  3  -1  -3  5 \[3  6  7]      **7**

>**Example 2:**
>**Input:** nums = [1], k = 1
>**Output:** [1]
## Approach
To maintain a sliding window that shifts by adding elements from the back and removing them from the front, a doubly-ended data structure is needed. In C++, the `deque` is ideal for performing `push_back` and `pop_front` operations. We start with two pointers: a left pointer and a right pointer, where the right pointer moves to the end of the array. Initially, all smaller elements are added to the dequeue. When an element larger than the ones in the dequeue is encountered, smaller elements are popped from the back of the dequeue to ensure the largest element stays at the front. Additionally, if the left pointer moves past the front of the dequeue, the front element is removed to maintain the window's bounds. **It's important to note that we are working with pointers to the array, not the elements themselves.** As the window size must be maintained, whenever the window exceeds its limit, we record the maximum element and increment the left pointer to ensure the window remains valid. The right pointer is then moved forward to continue processing.
## Code
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int l(0), r(0);
        deque<int> q;
        while (r < nums.size()) {
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);
            if (l > q.front())
                q.pop_front();
            if ((r + 1) >= k) {
                res.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return res;
    }
```
Tags: [[Sliding Window]], [[Deque]], [[Two Pointers]]
## Question Statement
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the `MinStack` class:
- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.
You must implement a solution with `O(1)` time complexity for each function.
## Example
**Example 1:**
>**Input**
>\["MinStack","push","push","push","getMin","pop","top","getMin"]
>\[[],\[-2],\[0],\[-3],[],[],[],[]]
>**Output**
>\[null,null,null,null,-3,null,0,-2]

>**Explanation**
>MinStack minStack = new MinStack();
>minStack.push(-2);
>minStack.push(0);
>minStack.push(-3);
>minStack.getMin(); // return -3
>minStack.pop();
>minStack.top();    // return 0
>minStack.getMin(); // return -2

## Approach
Implement two stacks, keep a standard stack, and a minstack to contain the smallest element so that the query is completed in constant time. 
## Code
```cpp
class MinStack {
public:
    stack<int> st;
    stack<int> minstack;
    MinStack() {}
    void push(int val) {
        st.push(val);
        if (minstack.empty() || minstack.top() >= val) {
            minstack.push(val);
        }
    }
    void pop() {
        if (getMin() == st.top()) {
            minstack.pop();
        }
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minstack.top(); }
};
```
## Approach 2
Stack will contain pair<int,int> where the values in the pair are <current_val, min_so_far>
## Approach 3
Instead of using two stacks, we can maintain a min variable and modified values inserted into the top of the stack using 2\*val - prev_min = new_val 
Tags: [[Stacks]]
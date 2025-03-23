## Question Statement
Given a stack, the task is to sort it such that the top of the stack has the greatest element.
## Approach
A stack can be sorted by recursively calling a sort function on the stack, where in each recursive call the top element of the stack is picked up/popped out, and is not pushed until it reaches it's right place in the recursive call stack.
## Code
```cpp
class SortedStack{
	public:
		stack<int> s;
		sort();
};
void insertElement(stack<int>& st, int temp){
	if(st.size() == 0 || st.top() <= temp){
		st.push(temp);
		return;
	}
	else{
		int temp = st.top();
		st.pop();
		insertEle(st,temp);
		st.push(temp);
	}
}
void SortedStack::sort(){
	if(s.size() == 0) return;
	int temp = s.top();
	s.pop();
	sort();
	insertElement(s,temp);
}
```
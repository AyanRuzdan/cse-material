## Question Statement
You are given an array **arr\[\]** of integers. You have to construct a singly linked list from the elements of the arr\[\] and return the head of the linked list.
## Examples
> **Example 1:**
> **Input:** arr\[\] = \[1, 2, 3, 4, 5\]
> **Output:** 1 -> 2 -> 3 -> 4 -> 5
## Approach
Make the first node from the first array element, which is the head. Also make a secondary pointer which initially points to the head as well. Then starting from the next array element iterate the array, inside the iteration make a temporary node for each array element, and point the secondary pointer's next to the temporary node. Then move the secondary pointer itself to the newly created node. This way in each iteration a new temporary node will be created upon which the secondary pointer will first point and the move upon it itself. Finally return head. 
## Code
```cpp
/* Linked List Node Structure
class Node {
	public:
	int data;
	Node* next;
	Node(int d) {
		data = d;
		next = nullptr;
	}
};
*/

class Solution {
	public:
	Node* arrayToList(vector<int>& arr) {
		// first array element head in all cases
		Node* head = new Node(arr[0]);
		// secondary pointer
		Node* n = head;
		// start from the 1th element
		for (size_t i = 1; i < arr.size(); i++) {
			// make temporary node
			Node* temp = new Node(arr[i]);
			// point secondary pointer to the temporary node
			n->next = temp;
			// move the secondary pointer onto the temporary node
			n = temp;
			// delete temp if required
			// loop
		}
		// finally return head
		return head;
	}
};
```
Tags: [[Arrays]], [[Linked Lists]]
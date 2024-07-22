## Question Statement
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value **target**.

## Examples
**Example 1:**
> Input:
> 	List:     1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
> 	Target: 7
> Output: (1, 6), (2, 5)

## Approach
Make two pointers start from the start and end of the doubly linked list. If the sum of the pointers equal the target, add it to the result vector. If the sum is larger than the target, move the end pointer backward, else move the start pointer forward.

Code:
```cpp
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
	    # Make resultant pair vector
        vector<pair<int, int>> res;
        # Make start pointer taking value of head
        Node* start = head;
        # Make end pointer initially taking the value of head
        Node* end = head;
        # Move end pointer to the last element
        while(end->next != NULL)
        end = end->next;
        # As the input is sorted, we can use this condition
        while(start->data < end->data){
	        # If target is equal to sum of start and end pointers
            if(start->data + end->data == target){
	            # Then push the pair in the result vector
                res.push_back({start->data, end->data});
                /* Also move start pointer forward and end pointer 
                backward as we don't need their values anymore */
	            start = start->next;
	            end = end->prev;}
            /* If sum is larger, then we move the end
            pointer backward to reduce the sum */
            else if(start->data + end->data > target)
                end = end->prev;
            // If sum is smaller, then move the start pointer forward
            else start = start->next;
            
        }
        return res;
        
    }
```

Tags: [[Linked Lists]], [[Two Pointers]], [[Two Way LL / Doubly LL]], [[Traversal of Doubly LL]]

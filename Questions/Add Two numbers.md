## Question Statement
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Tags: [[Linked Lists]]

## Examples
 **Example 1:**
> Input: l1 = [2,4,3], l2 = [5,6,4]
> Output: [7,0,8]

**Example 2:**
> **Input:** l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
**Output:** [8,9,9,9,0,0,0,1]

## Approach
Keep on adding new nodes that contain the value of the first digit of the sum. meanwhile carry the "carry" forward. After adding the sum, move the pointers forward. Return NULL if there is no next node. This might occur if one number is much larger than the other.
## Code
```cpp
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        # Dummy header
        ListNode* dummy = new ListNode(0);
        # Current copy starting from dummy
        ListNode* curr = dummy;
        int carry = 0;
        // Even when lists are exhausted, carry might be zero
        while (l1 != nullptr || l2 != NULL || carry != 0) {
	        /* if l1 is not null then take value 
	        else take zero*/
            int x = l1 ? l1->val : 0;
	        /* Similarly if l3 is not null then take 
	        value else take zero */
	        int y = l2 ? l2->val : 0;
            /* Take sum as addition of the numbers
            as well as the carry */
            int sum = carry + x + y;
            // Carry will be either 1 or 0, using division
            carry = sum / 10;
            // Make a new node as the sum unit digit
            // and point next to it
            curr->next = new ListNode(sum % 10);
            // Move current forward to make place
            // for new node
            curr = curr->next;
            // Also move original pointers forward
            // to take numberic values if they exist
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        // Point result to dummy next and delete dummy (Good Practice)
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
```


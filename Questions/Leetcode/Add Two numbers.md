## Question Statement

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
## Examples
 **Example 1:**
> Input: l1 = [2,4,3], l2 = [5,6,4]
> Output: [7,0,8]

**Example 2:**
>Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
>Output: [8,9,9,9,0,0,0,1]
## Approach (Iterative)
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
         /* Similarly if l2 is not null then take 
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

## Approach (Recursive)
In the recursive approach for adding two numbers represented as linked lists, the idea is to process one digit at a time while carrying the overflow to the next recursive call. At each step, we add the current digits from both lists along with the carry. From this sum, a new node is created containing the digit value `sum % 10`, while the carry `sum / 10` is passed forward to the next recursion. The function then calls itself recursively on the next pointers of both lists, attaching the result to the next of the newly created node. The recursion continues until both lists are fully traversed and no carry remains, at which point the base case returns `NULL`. This way, the linked list is built naturally through recursive calls, and the carry is seamlessly propagated until the very end.
## Code
```cpp
ListNode *add(ListNode *l1, ListNode *l2, int carry)
{
    if (!l1 && !l2 && carry == 0)
        return NULL;
    int sum = carry;
    if (l1)
    {
        sum += l1->val;
        l1 = l1->next;
    }
    if (l2)
    {
        sum += l2->val;
        l2 = l2->next;
    }
    ListNode *newNode = new ListNode(sum % 10);
    newNode->next = add(l1, l2, sum / 10);
    return newNode;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return add(l1, l2, 0);
}
```
Tags: [[Linked Lists]], [[Recursion]]

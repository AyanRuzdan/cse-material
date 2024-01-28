## Question Statement
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return _the head of the merged linked list_.

## Examples
**Examples 1:**
> **Input:** list1 = [1,2,4], list2 = [1,3,4]
> **Output:** [1,1,2,3,4,4]

**Example 2:**
> **Input:** list1 = [], list2 = []
> **Output:** []

**Example 3:**
> **Input:** list1 = [], list2 = [0]
> **Output:** [0]

## Approach
- The code first checks if either of the linked lists are empty. If either linked list is empty, the code returns the other linked list.
- Otherwise, the code compares the heads of the two linked lists and returns the head of the linked list with the smaller value. The code also stores the head of the linked list with the smaller value in a temporary variable called `temp`.
- The code then enters a while loop. The while loop continues to iterate while both linked lists are not empty. Inside the while loop, the code checks if the head of the first linked list is smaller than the head of the second linked list. If it is, the code appends the head of the first linked list to the merged linked list and moves the head of the first linked list forward. Otherwise, the code appends the head of the second linked list to the merged linked list and moves the head of the second linked list forward. The code also updates the current pointer of the merged linked list to point to the next node.
- After the while loop terminates, the code checks if the first linked list is empty. If it is, the code appends the second linked list to the merged linked list. Otherwise, the code appends the first linked list to the merged linked list. The code then returns the head of the merged linked list.
## Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
        return list2;
        if(list2 == nullptr)
        return list1;
        ListNode* temp = list1;
        if(list1->val > list2->val)
        {
            temp = list2;
            list2 = list2->next;
        }
        else
        list1 = list1->next;
        ListNode *curr = temp;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next; 
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(!list1) curr->next = list2;
        else curr->next = list1;
        return temp;
    }
};
```
Tags: [[Linked Lists]]
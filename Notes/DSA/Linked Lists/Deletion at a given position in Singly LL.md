Here only the node that is to be deleted is given, no head or any other pointer is provided.
```cpp
void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next ? node->next->next : NULL;
    }
```
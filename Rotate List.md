```cpp
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
        return head;
    int n = 1;
    ListNode *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        n++;
    }
    k = k % n;
    if (k == 0)
        return head;
    tail->next = head;
    ListNode *newTail = head;
    for (int i = 1; i < n - k; i++)
    {
        newTail = newTail->next;
    }
    ListNode *newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}
```
Tags: [[Linked Lists]], [[Linked List Cycle]]
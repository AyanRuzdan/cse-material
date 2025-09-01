```cpp
ListNode *mergeSortedLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    if (l1->val < l2->val)
    {
        l1->next = mergeSortedLists(l1->next, l2); // this points to sorted list
        return l1;
    }
    else
    {
        l2->next = mergeSortedLists(l1, l2->next); // this points to sorted list
        return l2;
    }
}
ListNode *findMid(ListNode *head)
{
    ListNode *s = head;
    ListNode *f = head->next;
    while (f != NULL && f->next != NULL)
        s = s->next, f = f->next->next;
    return s;
}
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head; // single element
    ListNode *mid = findMid(head);
    ListNode *right = mid->next;
    mid->next = NULL;
    ListNode *left = head;
    left = sortList(left);
    right = sortList(right);
    return mergeSortedLists(left, right);
}
```
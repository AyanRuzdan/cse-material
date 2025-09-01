```cpp
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *d1 = headA;
    ListNode *d2 = headB;
    while (d1 != d2)
    {
        if (d1 == NULL)
            d1 = headB;
        else
            d1 = d1->next;
        if (d2 == nullptr)
            d2 = headA;
        else
            d2 = d2->next;
    }
    return d1;
}
```
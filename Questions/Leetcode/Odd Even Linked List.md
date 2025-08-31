```cpp
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *l = head;
    ListNode *r = head->next;
    ListNode *eH = r;
    while (r && r->next)
    {
        l->next = l->next->next;
        r->next = r->next->next;
        l = l->next;
        r = r->next;
    }
    l->next = eH;
    return head;
}
```
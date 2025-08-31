```cpp
bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *prev = NULL;
    slow = slow->next;
    ListNode *curr = slow;
    while (curr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    ListNode *l = head;
    ListNode *r = prev;
    while (r)
    {
        if (l->val != r->val)
            return false;
        l = l->next;
        r = r->next;
    }
    return true;
}
```

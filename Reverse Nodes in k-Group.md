```cpp
ListNode *reverseLL(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *f = temp->next;
        temp->next = prev;
        prev = temp;
        temp = f;
    }
    return prev;
}
ListNode *getKthNode(ListNode *temp, int k)
{
    k--;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevLast = nullptr;
    while (temp != NULL)
    {
        ListNode *kthNode = getKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevLast)
            {
                prevLast->next = temp;
            }
            break;
        }
        ListNode *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}
```
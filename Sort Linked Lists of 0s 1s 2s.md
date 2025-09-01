```cpp
Node *segregate(Node *head)
{
    Node *zHead = new Node(-1);
    Node *zero = zHead;
    Node *oHead = new Node(-1);
    Node *one = oHead;
    Node *tHead = new Node(-1);
    Node *two = tHead;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = oHead->next ? oHead->next : tHead->next;
    one->next = tHead->next;
    two->next = NULL;
    return (zHead->next) ? zHead->next : (oHead->next ? oHead->next : tHead->next);
}
```
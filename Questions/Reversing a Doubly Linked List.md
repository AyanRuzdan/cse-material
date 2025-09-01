```cpp
Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *p = NULL;
    Node *c = head;
    while (c)
    {
        // swap begins here
        p = c->prev;
        c->prev = c->next;
        c->next = p;
        // swap ends here
        // move to next node using the prev pointer
        c = c->prev;
    }
    return p->prev;
}
```
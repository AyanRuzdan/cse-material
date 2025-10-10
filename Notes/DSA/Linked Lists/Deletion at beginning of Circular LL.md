---
cover:
---
```cpp
Node *deleteAtBeginning(Node *head)
{
    if (head == nullptr)
        return NULL;
    if (head->next == head)
        return NULL; // delete head for mem mgmt
    Node *last = head;
    while (last->next != head)
        last = last->next;
    Node *temp = head;
    head = head->next;
    last->next = head;
    delete temp;
    return head;
}
```
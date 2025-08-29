```cpp
Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = nullptr;
    return head;
}
```
Here `temp->next` is not assigned to `temp->next->next` as `temp->next->next` is already `NULL`

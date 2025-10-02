```cpp
void deleteAtPos(Node *&head, int pos)
{
    if (!head)
        return;
    if (pos == 1)
    {
        Node *temp = head;
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *last = head;
        while (last->next != head)
            last = last->next;
        last->next = head->next;
        head = head->next;
        delete temp;
        return;
    }
    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++)
        curr = curr->next;
    if (curr->next == head)
    {
        cout << "Out of range\n";
        return;
    }
    Node *toDelete = curr->next;
    curr->next = toDelete->next;
    delete toDelete;
}
```
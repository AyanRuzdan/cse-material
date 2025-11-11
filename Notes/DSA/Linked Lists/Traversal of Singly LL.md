## Code
```cpp
void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
```
Tags: [[Linked Lists]]
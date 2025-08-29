```cpp
Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```
For even return n/2 and for odd return (n+1)/2
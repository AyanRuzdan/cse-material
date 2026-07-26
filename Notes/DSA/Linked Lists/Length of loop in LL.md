```cpp
int lengthOfLoop(Node *head)
{
    // code here
    int count = 0;
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            Node *temp = slow->next;
            while (slow != temp)
            {
                count++;
                temp = temp->next;
            }
            return count + 1;
        }
    }
    return count;
}
```
Traversal of DLL is the same as for a normal LL. Make a temp pointer that points to the head, then traverse the temp pointer until it reaches the end, simultaneously print the data for the temp node in each iteration.
```cpp
void traverse()
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
```
Time Complexity: O(n)
Space Complexity: O(1)
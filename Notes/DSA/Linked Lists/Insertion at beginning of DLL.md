![img](https://media.geeksforgeeks.org/wp-content/uploads/20240806184053/Insertion-at-the-Beginning-in-Doubly-Linked-List.webp)

**Steps**:
 - Create a new node with previous pointer to `NULL`
 - Set next pointer of new node to head, `newNode->next = head`
 - Check if list is empty, and then update head, `head->prev = newNode`
 - Finally, return `newNode` as head of list

```cpp
Node *insertAtHead(Node *head, int val)
{
    // make a new Node
    Node *newNode = new Node(val);
    // point newNode's next to head
    newNode->next = head;
    // if list is not empty
    if (head != NULL)
    // point head's previous to newNode
        head->prev = newNode;
    // now as newNode is at the start, return newNode
    return newNode;
}
```

Time Complexity: O(1)
Space Complexity: O(1)
Tags: [[Linked Lists]]
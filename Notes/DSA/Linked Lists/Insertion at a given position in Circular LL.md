Before we insert a node, we need to check if the list is empty or not, and also if the position is not 1. If the position is 1, then we create a new node and make it point to itself. If the list is not empty, we create a new node and traverse the list to find the insertion point. If the position is 1, we insert the new node at the beginning by adjusting the pointers accordingly.
![img](https://media.geeksforgeeks.org/wp-content/uploads/20240806150431/Insertion-at-specific-position-of-circular-linked-list.webp)

```cpp
Node *insertAtPosition(Node *last, int data, int pos)
{
    if (last == NULL) // if the list is empty
    {
        if (pos != 1) // if specified position is invalid return last
            return last;
        // otherwise create new node for insertion
        Node *newNode = new Node(data);
        last = newNode; // last takes the value of newNode
        last->next = last; // loop for 1 node
        return last; // return last as we need not insert anymore
    }
    // if that is not the case then make new node
    Node *newNode = new Node(data);
    // next of last is head, and curr points to that node
    Node *curr = last->next;
    // if we have to insert at head
    if (pos == 1)
    {
        // newNode comes before curr
        newNode->next = curr;
        // last's next points to the newNode making it the first node
        last->next = newNode;
        return last;
    }
    // but if we need to insert in the middle somewhere then
    for (int i = 1; i < pos - 1; i++)
    {
        // move current until it specifies the given position
        curr = curr->next;
        // if we move forward and loop around to head again
        // then simply return last
        if (curr == last->next)
            return last;
    }
    // if curr lands somewhere in the middle then
    // change curr's pointer to newNode's pointer
    newNode->next = curr->next;
    // after that step, point curr to the newNode
    curr->next = newNode;
    // if after traversing curr lands on last node
    // then assign newNode to the last node
    if (curr == last)
        last = newNode;
    // finally return last node
    return last;
}
```
The time complexity for the specified algorithm is O(n), as we need to traverse the linked list only once. As for space complexity we are taking very less space for variables, hence O(1).
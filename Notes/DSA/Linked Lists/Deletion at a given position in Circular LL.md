To delete a node at a given position, we need to check a few edge cases before doing the deletion. If there is only one node, we can delete it without any issue, otherwise we would need a more general approach for node deletion. Also if the position to be deleted is the head, then we would be taking a different approach as compared to deleting a node forward in the linked list.
```cpp
struct Node
{
    int data;
    Node *next;
};
Node *deleteAtPosition(Node *head, int pos)
{
    if (head == nullptr || pos <= 0) // no node
        return head;
    Node *curr = head; // not disturbing head
    if (pos == 1) // deleting head
    {
        if (curr->next == head) // if pos is 1 and only one node is present
        {
            delete curr; // delete that node and
            return nullptr; // return NULL
        }
        Node *last = head; // otherwise search for last node
        while (last->next != head)
            last = last->next;
        last->next = head->next; // skip next from head->next to last->next
        Node *temp = head; // now head is pointerless but still needs deletion
        head = head->next; // can't delete head directly without designating it to the next node
        delete temp; // delete temp that was actually head
        return head; // return safe head
    }
    // deleting non-head
    for (int i = 1; i < pos - 1 && curr->next != head; i++)
    {
        curr = curr->next; // move one less pos
    }
    if (curr->next == head) // give position is too large and we ended up doing a loop around
        return head;
    Node *temp = curr->next; // assign temp as the node to be deleted
    curr->next = temp->next; // skip pointer from n to n+1
    delete temp; 
    return head;
}
Node *insertAtEnd(Node *head, int val)
{
    Node *newNode = new Node{val, nullptr};
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}
void printList(Node *head)
{
    if (head == nullptr)
        return;
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    lb
}
```
Few things that need to be taken care of are:
- `printList` in a circular LL is different from a singly LL.
- `insertAtEnd` returns a pointer to the head node, so we have to assign it to the head node every time we add a new node in the `main` function.
- `deleteAtPosition` works differently according to presence of `head` and `pos`
Tags: [[Circular LL]]
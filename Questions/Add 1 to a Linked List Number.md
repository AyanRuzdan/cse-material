```cpp
int addOneRR(Node *head)
{
    if (head == nullptr)
        return 1;
    int carry = addOneRR(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10;
}
Node *addOne(Node *head)
{
    int carry = addOneRR(head);
    if (carry)
    {
        Node *newNode = new Node(carry);
        newNode->next = head;
        head = newNode;
    }
    return head;
}
```
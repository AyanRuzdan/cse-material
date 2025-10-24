```cpp
Node *deleteAtEnd(Node *head)
{
	if (!head)
		return NULL;
	if (head->next == head)
	{
		return NULL;
	}
	Node *temp = head;
	while (temp->next->next != head)
		temp = temp->next;
	Node *last = temp->next;
	temp->next = head;
	return head;
}
```
Tags: [[Circular LL]]
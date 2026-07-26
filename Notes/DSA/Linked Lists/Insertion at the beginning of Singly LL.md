## Code
### Function to return pointer to head after insertion 
```cpp
Node *insertHead(Node *head, int val)
{
    return new Node(val, head);
}
```
### Constructor to insert node and point to a given pointer
```cpp
class Node
{
public:
    int data;
    Node *next;
    Node(int val, Node *next) : data(val), next(next) {}
};
```
### Inserting values in main function
```cpp
    head = insertHead(head, 0);
```

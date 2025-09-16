## Approach (Recursive)
```cpp
void traverseLeft(Node *r)
{
    if (!r)
        return;
    if (r->left)
    {
        cout << r->val << " ";
        traverseLeft(r->left);
    }
    else if (r->right)
    {
        cout << r->val << " ";
        traverseLeft(r->right);
    }
}
void getLeafNode(Node *r)
{
    if (!r)
        return;
    getLeafNode(r->left);
    if (!r->left && !r->right)
    {
        cout << r->val << " ";
    }
    getLeafNode(r->right);
}
void traverseRight(Node *r)
{
    if (!r)
        return;
    if (r->right)
    {
        traverseRight(r->right);
        cout << r->val << " ";
    }
    else if (r->left)
    {
        traverseRight(r->left);
        cout << r->val << " ";
    }
}
```
Tags: [[Binary Trees]], [[Recursion]]
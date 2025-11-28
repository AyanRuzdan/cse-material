## Code
```cpp
void lvlOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            auto x = q.front();
            q.pop();
            cout << x->val << " ";
            if (x->left)
                q.push(x->left);
            if (x->right)
                q.push(x->right);
        }
        lb
    }
}
```
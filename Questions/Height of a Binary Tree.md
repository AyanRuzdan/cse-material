```cpp
int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int ans = 0;
    ans = 1 + max(maxDepth(root->left), maxDepth(root->right));
    return ans;
}
```

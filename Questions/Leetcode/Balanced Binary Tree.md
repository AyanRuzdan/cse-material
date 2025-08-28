```cpp
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int ans = 0;
    ans = 1 + max(height(root->left), height(root->right));
    return ans;
}
bool isBalanced(TreeNode *root)
{
    if (root == nullptr)
        return true;
    if (abs(height(root->left) - height(root->right)) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
```

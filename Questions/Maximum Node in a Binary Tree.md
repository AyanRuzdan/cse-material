## Code
```cpp
int findMax(TreeNode *root)
{
    if (!root->left && !root->right)
        return root->val;
    int leftMax = INT_MIN, rightMax = INT_MIN;
    if (root->left)
        leftMax = findMax(root->left);
    if (root->right)
        rightMax = findMax(root->right);
    return max({root->val, leftMax, rightMax});
}
```
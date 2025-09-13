```cpp
int solve(TreeNode *root, int &res)
{
    if (root == nullptr)
        return 0;
    // zeroes are used with max to leave out negative values
    int l = max(0, solve(root->left, res));
    int r = max(0, solve(root->right, res));
    res = max(res, l + r + root->val);
    return max(l, r) + root->val;
}
int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    solve(root, res);
    return res;
}
```
Tags: [[Binary Trees]], [[Recursion]]
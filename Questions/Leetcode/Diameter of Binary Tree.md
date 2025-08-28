## Definition
Diameter of a tree is defined as the longest distance between any two nodes which may or may not pass through the root of the tree.
## Approach
The diameter of a tree is calculated by calculating the height of each nodes' left and right subtree and then summing it and comparing it with a maximum.
## Code
```cpp
int height(TreeNode *root, int &ans)
{
    if (root == nullptr)
        return 0;
    int l = height(root->left, ans);
    int r = height(root->right, ans);
    ans = max(ans, 1 + l + r);
    return 1 + max(l, r);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    height(root, ans);
    return ans - 1;
}
```

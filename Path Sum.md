## Question Statement
Find bool value of root to leaf such that path sum is equal to a target value
## Code
```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        if (root->val == targetSum && (!root->left && !root->right))
            return true;
        if ((!root->left && !root->right) && root->val < targetSum)
            return false;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
```
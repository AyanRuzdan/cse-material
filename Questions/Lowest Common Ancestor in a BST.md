## Code
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;
        if (root == p || root == q)
            return root;
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if (l && r) return root; // on either side
        if (l) return l; // both are on left
        if (r) return r; // both are on right
        return nullptr;
    }
};
```

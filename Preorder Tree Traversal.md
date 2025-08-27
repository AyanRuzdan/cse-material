```cpp
void preorder(vector<int> &res, TreeNode *root)
{
    if (root == nullptr)
        return;
    res.push_back(root->val);
    preorder(res, root->left);
    preorder(res, root->right);
}
vector<int> preorderTraversal(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<int> res;
    preorder(res, root);
    return res;
}
```

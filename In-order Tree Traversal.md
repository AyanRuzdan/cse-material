```cpp
void inorder(vector<int> &res, TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(res, root->left);
    res.push_back(root->val);
    inorder(res, root->right);
}
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    inorder(res, root);
    return res;
}
```
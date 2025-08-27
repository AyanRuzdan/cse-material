## Recursive
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
## Iterative
```cpp
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return {};
    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (!st.empty() || curr != nullptr)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
```

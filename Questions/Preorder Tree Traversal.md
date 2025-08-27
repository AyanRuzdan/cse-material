## Recursive
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
## Iterative
```cpp
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return {};
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        auto x = st.top();
        st.pop();
        res.push_back(x->val);
        if (x->right)
            st.push(x->right);
        if (x->left)
            st.push(x->left);
    }
    return res;
}
```

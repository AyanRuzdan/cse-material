## Approach (Array reverse)
```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == nullptr)
        return {};
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    bool ltr = 1;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            auto node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (ltr)
            res.push_back(temp);
        else
        {
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        ltr ^= 1;
    }
    return res;
}
```
Tags: [[Binary Trees]], [[Queues]]
## Question Statement
Given the `root` of a binary search tree, return _a **balanced** binary search tree with the same node values_. If there is more than one answer, return **any of them**.

A binary search tree is **balanced** if the depth of the two subtrees of every node never differs by more than `1`.
## Examples

**Example 1:**
![](https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg)

>**Input:** root = [1,null,2,null,3,null,4,null,null]
>**Output:** [2,1,3,null,null,null,4]
>**Explanation:** This is not the only correct answer, [3,1,4,null,2] is also correct.

**Example 2:**
![](https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg)

>**Input:** root = [2,1,3]
>**Output:** [2,1,3]

## Approach
First put the tree into a sorted list using inorder traversal, then make a balanced AVL tree by recursively splitting the list in half. See code.
## Code
```cpp
void inor(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr)
            return;
        inor(root->left, inorder);
        inorder.push_back(root->val);
        inor(root->right, inorder);
    }
    TreeNode* avl(vector<int>& inor, int left, int right) {
        if (left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode* lefty = avl(inor, left, mid - 1);
        TreeNode* righty = avl(inor, mid + 1, right);
        return new TreeNode(inor[mid], lefty, righty);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inor(root, inorder);
        int n = inorder.size();
        return avl(inorder, 0, n - 1);
    }
```
Tags: [[Binary Search Tree]], [[Recursion]]
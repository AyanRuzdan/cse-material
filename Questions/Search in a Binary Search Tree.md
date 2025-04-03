## Question Statement
You are given the `root` of a binary search tree (BST) and an integer `val`.
Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.
>**Example** 1:
>![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)
>**Input**: root = [4,2,7,1,3], val = 2
>**Output**: [2,1,3]

>**Example** 2:
>![](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)
>**Input:** root = [4,2,7,1,3], val = 5
>**Output:** []

## Approach 1 (Recursive)
Using the property of a binary search tree, a node can be located in a BST recursively depending on whether it is smaller or larger than the current node. If the current node is smaller than the target, we search the right subtree, and if the current node is larger than the target then we search the left subtree. We use a recursive function to search left and right through the required subtrees until we find the required nodes.
## Code
```cpp
TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return NULL;
        if (root->val == val)
            return root;
        else if (root->val > val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
```
Time Complexity: $O(logn)$
Space Complexity: $O(1)$
Tags: [[Recursion]], [[Binary Search Tree]], [[Search in a BST]]
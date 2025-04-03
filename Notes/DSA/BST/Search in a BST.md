If an element exists in a binary search tree, it can be found in $O(logn)$ time using the property of the binary search tree, where each element to the left is smaller than the parent, and each element to the right is larger. The same is true for subtrees as well.
![](https://static.takeuforward.org/content/search-in-bst-image4-DptF1M1k)
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
Here the function returns the address of the node where the item is present. A boolean function can also be used to return if the element is present in the BST or not.
Time Complexity: $O(logn)$
Space Complexity: $O(1)$
Tags: [[Binary Search Tree]]
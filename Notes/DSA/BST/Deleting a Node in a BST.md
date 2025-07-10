Deleting a node in a BST can be broken down into three scenarios.
1. [[#Deleting a leaf node]]
2. [[#Deleting a node with a single child]]
3. [[#Deleting a node with two children/subtrees]]
## Deleting a leaf node
A leaf node has no children, simply remove the node from the tree and update it's corresponding child pointer to NULL.
## Deleting a node with a single child
If it is a single child, then it could be either left or right child. In that case, replace the node with it's only child and update the parent of that node to point directly to it's child.
## Deleting a node with two children/subtrees
When it comes to deleting a node with two children, first we need to find the inorder successor. Then replace the node's value with successor's or predecessor's value. Finally delete the successor/predecessor node.
## Code
```cpp
TreeNode *deletenode(TreeNode *root, int val)
    {
        if (root == nullptr)
            return NULL;
        if (val < root->data)
        {
            root->left = deletenode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = deletenode(root->right, val);
        }
        else
        {
            if (!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            else if (!root->left || !root->right)
            {
                TreeNode *temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            else
            {
                TreeNode *successor = getMinNode(root->right);
                root->data = successor->data;
                root->right = deletenode(root->right, successor->data);
            }
        }
        return root;
    }
    TreeNode *getMinNode(TreeNode *root)
    {
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }
```
Tags: [[Binary Search Tree]]
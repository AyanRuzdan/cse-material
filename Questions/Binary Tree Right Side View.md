## Question Statement
Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return _the values of the nodes you can see ordered from top to bottom_.
## Examples
>Example 1:
>Input: root = [1,2,3,null,5,null,4]
>Output: [1,3,4]
>Explanation:
>![](https://assets.leetcode.com/uploads/2024/11/24/tmpd5jn43fs-1.png)

>Example 2:
>Input: root = [1,2,3,4,null,null,null,5]
>Output: [1,3,4,5]
>Explanation:
>![](https://assets.leetcode.com/uploads/2024/11/24/tmpkpe40xeh-1.png)

>Example 3:
>Input: root = [1,null,3]
>Output: [1,3]
>Example 4:
>Input: root = []
>Output: []
## Approach
As the question demands right side view of the binary tree, the initial approach is to be storing the nodes in a level order, and then display the *last* node in the level. In order to achieve that we can use a queue to store the nodes level order wise. In every level we can check the number of nodes in the level, and pop the nodes from the queue according to the size of the level, leaving the last node to be used as a result. Every other node is to be pushed into the queue for the next level.
## Code
```cpp
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) // return empty list if no nodes
            return {};
        vector<int> res;
        queue<TreeNode*> q; // queue with Node type
        q.push(root); // start with root node
        while (!q.empty()) { // work as long as there are nodes in the queue
            int levelSize = q.size(); // needs to be initialized every time to get new level size
            while (levelSize--) { // iterate for level length
                auto topNode = q.front();
                q.pop();
                if (n == 0) // for last/rightest node
                    res.push_back(topNode->val); // push into result vector
                if (topNode->left)
                    q.push(topNode->left); // push next level nodes into queue
                if (topNode->right)
                    q.push(topNode->right); // push next level nodes into queue
            }
        }
        return res;
    }
```

Time Complexity: $O(n)$, where $n$ is the number of nodes in the tree.
Space Complexity: $O(w)$, where $w$ is the maximum width of a level
Tags: [[Trees]]
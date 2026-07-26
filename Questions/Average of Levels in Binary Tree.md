Given the `root` of a binary tree, return _the average value of the nodes on each level in the form of an array_. Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg)

**Input:** root = \[3,9,20,null,null,15,7]
**Output:** \[3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return \[3, 14.5, 11].

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg)

**Input:** root = \[3,9,20,15,7]
**Output:** \[3.00000,14.50000,11.00000]
## Approach
Use level order traversal to get all nodes of the same level in a each iteration. In every level add sum of all nodes and divide it by queue size. Get the average value and insert in resultant vector.
## Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> res;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            double accu = 0;
            for (int i = 0; i < n; i++) {
                auto x = q.front();
                q.pop();
                accu += x->val;
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            res.push_back(accu / (n * 1.00000));
        }
        return res;
    }
};
```
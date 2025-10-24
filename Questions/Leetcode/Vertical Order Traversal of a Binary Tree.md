---
cover: https://static.takeuforward.org/content/vertical-traversal-image4-aWuNOE3V
---
## Question Statement
Given the `root` of a binary tree, calculate the **vertical order traversal** of the binary tree.
For each node at position `(row, col)`, its left and right children will be at positions `(row + 1, col - 1)` and `(row + 1, col + 1)` respectively. The root of the tree is at `(0, 0)`.
The **vertical order traversal** of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return _the **vertical order traversal** of the binary tree_.
## Examples
>Example 1:
>![](https://assets.leetcode.com/uploads/2021/01/29/vtree1.jpg)
>Input: root = \[3,9,20,null,null,15,7]
>Output: \[[9],[3,15],[20],[7]]
>Explanation:
>Column -1: Only node 9 is in this column.
>Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
>Column 1: Only node 20 is in this column.
>Column 2: Only node 7 is in this column.

>Example 2:
>![](https://assets.leetcode.com/uploads/2021/01/29/vtree2.jpg)
>Input: root = [1,2,3,4,5,6,7]
>Output: [[4],[2],[1,5,6],[3],[7]]
>Explanation:
>Column -2: Only node 4 is in this column.
>Column -1: Only node 2 is in this column.
>Column 0: Nodes 1, 5, and 6 are in this column. 1 is at the top, so it comes first. 5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

**Example 3:**

![](https://assets.leetcode.com/uploads/2021/01/29/vtree3.jpg)

**Input:** root = [1,2,3,4,6,5,7]
**Output:** [[4],[2],[1,5,6],[3],[7]]
**Explanation:**
This case is the exact same as example 2, but with nodes 5 and 6 swapped.
Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.
## Approach
A hashmap containing coordinates of every node and node value will be used. Map will be populated using recursive tree traversal. After that for every `y or col` value the values will be filled in the temporary list. A temporary list is required so that overlapping values can be sorted before returning the answer.
## Code
```cpp
void traverse(map<int, vector<pair<int, int>>> &mp, TreeNode *root, int x, int y)
{
    if (root == nullptr)
        return;
    mp[x].push_back({y, root->val});
    traverse(mp, root->left, x - 1, y + 1);
    traverse(mp, root->right, x + 1, y + 1);
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, vector<pair<int, int>>> mp;
    _(mp, root, 0, 0);
    vector<vector<int>> res;
    for (auto &item : mp)
    {
        auto vect = item.second;
        sort(vect.begin(), vect.end());
        vector<int> temp;
        for (auto &values : vect)
        {
            temp.push_back(values.second);
        }
        res.push_back(temp);
    }
    return res;
}
```
Tags: [[Binary Trees]]
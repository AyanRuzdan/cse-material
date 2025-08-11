## Question Statement
Given a binary **tree**, return an array where elements represent the bottom view of the binary tree from left to right.
Note: If there are **multiple** bottom-most nodes for a horizontal distance from the root, then the **later** one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottom most nodes at a horizontal distance of 0 from the root, here **34** will be considered.
## Examples
**Example 1:**
**Input:** [1,3,2]
**Output**: [3, 1, 2]
**Example 2:**
**Input:** [10, 20, 30, 40, 60]
**Output:** [40, 20, 60, 30]
>Note: The order of filling the tree is in complete binary tree method
## Approach (Recursive)
Each node can be assigned an $(x,y)$ coordinate which can be recursively assigned to each node. For each node if there is a node already present at it's `y` position it gets replaced with a new lower/deeper `y` value. Once all nodes are assigned their coordinate value into a map, we can use the `y` value to print the values in non-descending order of depth.
For a given node only using `x` value and rewriting upon it does not guarantee a solution as we are running a depth first search using recursion, hence we might overwrite a deeper value on the left with a shallow value on the right, that's why a `y` value is also required.
## Code
```cpp
  void traverse(Node* root, map<int, pair<int, int>>& mp, int depth, int hDist) {
    // Base case: stop when reaching a null node
    if (root == nullptr) return;
    // If no node is recorded for this horizontal distance OR
    // if the current node is deeper than the recorded one, update the map
    if (mp.find(hDist) == mp.end() || depth >= mp[hDist].first)
        // Store the node's depth and value for this horizontal distance
        mp[hDist] = {depth, root->data};
    // Recurse to the left child: increase depth, decrease horizontal distance
    traverse(root->left, mp, depth + 1, hDist - 1);
    // Recurse to the right child: increase depth, increase horizontal distance
    traverse(root->right, mp, depth + 1, hDist + 1);
}
vector<int> bottomView(Node *root) {
    // Map of horizontal distance → {depth, node value}
    map<int, pair<int, int>> mp;
    // Fill the map using DFS traversal
    traverse(root, mp, 0, 0);
    // Resultant list of node values for the bottom view
    vector<int> res;
    // Extract only the node values in order of horizontal distance
    for (auto item : mp) {
        res.push_back(item.second.second);
    }
    return res;
}
```
Tags: [[Binary Trees]], [[Recursion]]
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
	// for reaching null node i.e. base case
	if (root == nullptr) return;
	// check for that x value a node already exists or the current depth is lesser than new depth
	if (mp.find(hDist) == mp.end() || depth >= mp[hDist].first)
	 // assign that node to new x and depth value 
		mp[hDist] = {depth, root->data};
	// go left with more depth and less horizontal dist
	traverse(root->left, mp, depth + 1, hDist - 1); 
	// go right with more depth and more horizontal dist
	traverse(root->right, mp, depth + 1, hDist + 1); 
}
vector<int> bottomView(Node *root) {
	map<int, pair<int, int>> mp; // make a map with {node: {x, y}}
	traverse(root, mp, 0, 0); // recursive function
	vector<int> res; // resultant list  
	for (auto item : mp) {
		res.push_back(item.second.second); // insert only root->data into the vector
	}
	return res;
}
```
Tags: [[Binary Trees]], [[Recursion]]
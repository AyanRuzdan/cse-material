## Question Statement
For a binary tree, find the level with the maximum number of nodes.
## Approach(Recursive)
Use a hashmap to store the vertical depth and with each `y` value store the list of nodes for that corresponding vertical depth. Then iterate through the map keeping track of the depth that contains the largest list i.e. the maximum number of nodes and return respectively. *Some questions might demand the first found level with the maximum nodes, and that might cause an issue. Workaround includes extra space to keep all levels with have the most node and then returning the first level. See code.*
## Code
```cpp
void solve(map<int,vector<int>>& mp, Node* root, int y){
        if(root == nullptr) return;
        mp[y].push_back(root->data);
        solve(mp, root->left, y+1);
        solve(mp, root->right, y+1);
    }
    // Return the level (0-indexed) with maximum number of nodes.
    int maxNodeLevel(Node *root) {
        int maxi = INT_MIN;
        int level = 0;
        // Add your code here
        map<int,vector<int>> mp;
        solve(mp, root, 0);
        for(auto p:mp){
            maxi = max(maxi, int(p.second.size()));
        }
        vector<int> v;
        for(auto p:mp){
            if(p.second.size() == maxi){
                v.push_back(p.first);
            }
        }
        return *min_element(v.begin(), v.end());
    }
```
Tags: [[Recursion]], [[Binary Trees]]
```cpp
class Solution {
    unordered_map<int, vector<TreeNode*>> memo;

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0)
            return {};
        if (n == 1)
            return {new TreeNode(0)};
        if (memo.count(n))
            return memo[n];
        vector<TreeNode*> res;
        for (int lNodes = 1; lNodes < n; lNodes += 2) {
            int rNodes = n - lNodes - 1;
            vector<TreeNode*> lList = allPossibleFBT(lNodes);
            vector<TreeNode*> rList = allPossibleFBT(rNodes);
            for (auto lNode : lList) {
                for (auto rNode : rList) {
                    TreeNode* temp = new TreeNode(0);
                    temp->left = lNode;
                    temp->right = rNode;
                    res.push_back(temp);
                }
            }
        }
        memo[n] = res;
        return memo[n];
    }
};
```

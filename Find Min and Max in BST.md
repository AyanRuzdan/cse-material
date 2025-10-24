```cpp
int _(TreeNode* root){
if(!root) return INT_MAX;
return min({root->val, _(root->left), _(root->right)});
}
```
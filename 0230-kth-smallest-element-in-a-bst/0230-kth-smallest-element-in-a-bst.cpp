/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *node,int &k,int &ans){
        if(!node) return ;
         solve(node->left,k,ans);
        --k;
        if(k==0)  ans=node->val;
        solve(node->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
      solve(root,k,ans);
      return ans;
    }
};
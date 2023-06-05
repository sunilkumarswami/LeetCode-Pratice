/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* node, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(!node) return false;
        bool left=solve(node->left,p,q,ans);
        bool right=solve(node->right,p,q,ans);
        if(node==p || node==q){
            if(left || right){
                ans=node;
            }
            return true;
        }
        if(left && right){
                ans=node;
                return true;
            }
        if(left || right) return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        bool b= solve(root,p,q,ans);
        return ans;
    }
};
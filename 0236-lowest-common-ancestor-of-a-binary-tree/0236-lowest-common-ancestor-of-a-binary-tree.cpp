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
    TreeNode* solve(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node || node==p || node==q) return node;
        TreeNode* left=solve(node->left,p,q);
        TreeNode* right=solve(node->right,p,q);
        if(left && right){
            return node;
        }
        if(left ){
                return left;
            }
        if(right) return right;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
      
    }
};
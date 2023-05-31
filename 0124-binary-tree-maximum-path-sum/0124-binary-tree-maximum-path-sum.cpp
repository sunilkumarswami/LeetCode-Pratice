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
    int solve(TreeNode* node,int &maxi){
        if(!node) return 0;
        int rs=solve(node->right,maxi);
        int ls=solve(node->left,maxi);
        int val=node->val;
        if(ls>0) val+=ls;
        if(rs>0) val+=rs;
        maxi=max(maxi,val);
        
        // int ans=max(0,max(ls,rs));
        return node->val+max(0,max(ls,rs));
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int x= solve(root,maxi);
        return maxi;
    }
};
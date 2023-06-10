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
    bool solve(TreeNode* node,long long &last){
        if(!node) return true;
        if(!solve(node->left,last)) return false;
        if(node->val<=last) return false;
        last=node->val;
        return solve(node->right,last);
    }
    bool isValidBST(TreeNode* root) {
        long long last=LONG_MIN;
        return solve(root,last);
    }
};
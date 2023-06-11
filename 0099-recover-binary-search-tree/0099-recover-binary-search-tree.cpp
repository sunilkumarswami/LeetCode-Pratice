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
    void solve(TreeNode* node,TreeNode* &last,TreeNode* &first, TreeNode* &sec){
        if(!node) return;
        solve(node->left,last,first,sec);
        if(last && last->val>node->val){
            if(!first) first=last;
            sec=node;
        }
        last=node;
        solve(node->right,last,first,sec);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *last,*first,*sec;
        last=first=sec=NULL;
        solve(root,last,first,sec);
        swap(first->val,sec->val);
    }
};
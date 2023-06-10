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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key){
            TreeNode* temp=root;
            if(!root->right) {
                TreeNode* temp=root->left;
                root->left=NULL;
                return temp;
            }
            TreeNode *node=root->right;
            TreeNode *cur=node;
            while(cur->left) cur=cur->left;
            cur->left=root->left;
            root->left=NULL;
            root->right=NULL;
            return node;
        }
        TreeNode *par=root;
        while(par){
            if(par->left && par->left->val==key){
                TreeNode *node=par->left,*temp=par->left;
                if(!node->right) {
                    TreeNode* temp=node->left;
                    node->left=NULL;
                    par->left=temp;
                    return root;
                }
                TreeNode *ryt=node->right,*lft=node->left,*cur=ryt;
                while(cur->left) cur=cur->left;
                cur->left=lft;
                par->left=ryt;
                node->left=node->right=NULL;
                return root;
            }
            if(par->right && par->right->val==key){
                TreeNode *node=par->right;
                if(!node->right) {
                    TreeNode* temp=node->left;
                    node->left=NULL;
                    par->right=temp;
                    
                    return root;
                }
                TreeNode *ryt=node->right,*lft=node->left,*cur=ryt;
                while(cur->left) cur=cur->left;
                cur->left=lft;
                par->right=ryt;
                node->left=node->right=NULL;
                return root;
            }
            if(par->val>=key) par=par->left;
            else par=par->right;
        }
        return root;
    }
};
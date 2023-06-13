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
    void flatten(TreeNode* root) {
        TreeNode* node=root;
        
        while(node){
            if(!node->left){
                node=node->right;
            }
            else{
                TreeNode *cur=node->left;
                while(cur->right){
                    cur=cur->right;
                }
                
                cur->right=node->right;
                node->right=node->left;
                node->left=NULL;
            }
        }
    }
};
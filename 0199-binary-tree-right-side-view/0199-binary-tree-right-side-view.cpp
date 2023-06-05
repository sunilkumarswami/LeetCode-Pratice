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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        TreeNode *node=root;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            bool flag=false;
            while(size--){
                
                TreeNode *node=q.front();
                q.pop();
                if(size==0){
                    // flag=true;
                    ans.push_back(node->val);
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
        }
        return ans;
    }
};
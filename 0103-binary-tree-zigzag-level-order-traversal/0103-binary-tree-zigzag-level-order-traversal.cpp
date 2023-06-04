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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        
        int flag=1;
        q.push(root);
        while(true){
            vector<TreeNode*> v;
            vector<int> a;
            while(!q.empty()){
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node);
                // a.push_back(node->val);
            }
            if(v.empty()) return ans;
            if(flag==0) reverse(v.begin(),v.end());
            
            for(auto node:v){
                a.push_back(node->val);
                // ans.back().push_back(node->val);
            } 
            ans.push_back(a);
            if(flag==0) reverse(v.begin(),v.end());
            for(auto node:v){
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            } 
            flag=1-flag;
            
        }
        return ans;
    }
};
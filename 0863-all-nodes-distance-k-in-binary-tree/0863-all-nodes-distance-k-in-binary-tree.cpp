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
    void solve(TreeNode* node,int dist,int k,vector<int> &ans,unordered_map<TreeNode*,bool> &vis,map<TreeNode*,TreeNode*> par){
        if(!node || vis[node]) return;
        vis[node]=true;
        if(dist==k){
            ans.push_back(node->val);
            return;
        }
        dist++;
        if(node->left) solve(node->left,dist,k,ans,vis,par);
        if(node->right) solve(node->right,dist,k,ans,vis,par);
        solve(par[node],dist,k,ans,vis,par);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> par;
        queue<TreeNode*>q;
        q.push(root);
        par[root]=NULL;
        unordered_map<TreeNode*,bool> vis;
        vis[root]=false;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            vis[node]=false;
            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right]=node;
                q.push(node->right);
            }
        }
        
        vector<int> ans;
        solve(target,0,k,ans,vis,par);
        return ans;
    }
};
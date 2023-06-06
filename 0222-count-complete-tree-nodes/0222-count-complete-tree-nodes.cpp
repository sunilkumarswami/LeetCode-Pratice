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
    bool solve(TreeNode* node,int dist,int &cnt,int k){
        if(dist==k){
            if(node->left && node->right) 
            {
                cnt+=2;
                return false;
                }
            else if(node->left) 
            {
                cnt++;
                return true;
                           }
                
            else return true;
        }
        
        if(solve(node->left,dist+1,cnt,k) || solve(node->right,dist+1,cnt,k)) return true;
        return false;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int ans=0,len=0,cnt=0,dist=0;
        TreeNode *node=root;
        while(node){
            len++;
            node=node->left;
        }
        
        bool b=solve(root,1,cnt,len-1);
        
        for(int i=0;i<len-1;i++)
            ans+=pow(2,i);
        
        ans+=cnt;
        return ans;
    }
};
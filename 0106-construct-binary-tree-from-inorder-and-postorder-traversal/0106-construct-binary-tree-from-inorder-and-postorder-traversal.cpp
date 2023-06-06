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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int postl,int postr,int inl,int inr){
        if(postl>postr) return NULL;
        TreeNode* node=new TreeNode(postorder[postr]);
        if(postl==postr) return node;
        int i=inl,diff=0;
        for(;i<=inr;i++){
            if(inorder[i]==postorder[postr]) break;
        }
        diff=i-inl;
        node->left=solve(postorder,inorder,postl,postl+diff-1,inl,i-1);
        node->right=solve(postorder,inorder,postl+diff,postr-1,i+1,inr);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }
};
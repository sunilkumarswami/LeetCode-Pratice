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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int prel,int prer,int inl,int inr){
        if(prel>prer) return NULL;
        TreeNode* node=new TreeNode(preorder[prel]);
        if(prel==prer) return node;
        int i=inl,diff=0;
        for(;i<=inr;i++){
            if(inorder[i]==preorder[prel]) break;
        }
        diff=i-inl;
        node->left=solve(preorder,inorder,prel+1,prel+diff,inl,i-1);
        node->right=solve(preorder,inorder,prel+diff+1,prer,i+1,inr);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
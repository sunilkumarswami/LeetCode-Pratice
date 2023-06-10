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
    TreeNode* solve(vector<int> pre,int l,int r){
        if(l>r) return NULL;
        TreeNode* node=new TreeNode(pre[l]);
        if(l==r) return node;
        int i=l+1;
        for(;i<=r;i++){
            if(pre[i]>pre[l]) break;
        }
        TreeNode* lft=solve(pre,l+1,i-1);
        TreeNode* ryt=solve(pre,i,r);
        node->left=lft;
        node->right=ryt;
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);
    }
};
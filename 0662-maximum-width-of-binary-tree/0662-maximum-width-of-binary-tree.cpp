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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi=1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long size=q.size();
            long long first=q.front().second,last=q.front().second;
            while(size--){
                TreeNode* node=q.front().first;
                long long x=q.front().second;
                last=x;
                q.pop();
                if(node->left) q.push({node->left,2*x-first});
                if(node->right) q.push({node->right,2*x+1-first});
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};
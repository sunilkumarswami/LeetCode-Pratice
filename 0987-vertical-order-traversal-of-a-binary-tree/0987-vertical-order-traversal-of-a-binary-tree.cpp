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
    void traverse(TreeNode* node, int &x, int &y, map<int, multiset<pair<int,int>>> &mp){
        if(!node) return;
        mp[y].insert({x,node->val});
        int tempx=x+1,tempy=y-1;
        traverse(node->left,tempx,tempy,mp);
        tempy=y+1;
        traverse(node->right,tempx,tempy,mp);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,multiset<pair<int,int>>> mp;
        int x=0,y=0;
        traverse(root,x,y,mp);
        
        for(auto x:mp){
            multiset<pair<int,int>> st=x.second;
            vector<int> v;
            for(auto it:st){
                v.push_back(it.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
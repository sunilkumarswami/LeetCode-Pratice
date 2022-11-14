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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int cnt=0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> v;
            while(size--){
                TreeNode *node=q.front();
                v.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            vector<int> v1(v.begin(),v.end());
            map<int,int> mp;
            for(int i=0;i<v.size();i++){
                mp[v[i]]=i;
            }
            sort(v1.begin(),v1.end());
            for(int i=0;i<v1.size();i++){
                int val=v1[i];
                int ind=mp[val];
                if(i!=ind){
                    cnt++;
                    mp[v[i]]=ind;
                    swap(v[ind],v[i]);
                }
            }
        }
        return cnt;
    }
};
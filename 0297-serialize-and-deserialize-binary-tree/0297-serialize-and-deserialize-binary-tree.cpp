/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans+=to_string(root->val);
        ans+=',';
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                ans+=to_string(node->left->val);
                ans+=',';
            }
            else ans+="#,";
            if(node->right){
                q.push(node->right);
                ans+=to_string(node->right->val);
                ans+=',';
            }
            else ans+="#,";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s.empty()) return NULL;
        stringstream ss(s);
        string str;
        
        getline(ss,str,',');
        TreeNode *root=new TreeNode(stoi(str));
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
           TreeNode *node=q.front();
           q.pop();
           getline(ss,str,',');
           if(str!="#") node->left=new TreeNode(stoi(str));
           else node->left=NULL;
           getline(ss,str,',');
           if(str!="#") node->right=new TreeNode(stoi(str));
           else node->right=NULL;
           
           if(node->left) q.push(node->left);
           if(node->right) q.push(node->right);
       }
             return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
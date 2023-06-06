//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* find(Node* root,int x){
        if(!root) return NULL;
        if(root->data==x) return root;
        Node *left=find(root->left,x);
        Node *right=find(root->right,x);
        if(left) return left;
        return right;
    }
    
    int minTime(Node* root, int x) 
    {
        Node *target=find(root,x);
        map<Node*,Node*> par;
        queue<Node*>q;
        q.push(root);
        // par[root]=NULL;
        unordered_map<Node*,bool> vis;
        vis[root]=false;
        while(!q.empty()){
            Node* node=q.front();
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
        
        q.push(target);
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            if(size) dist++;
            while(size--){
                Node *node=q.front();
                vis[node]=true;
                q.pop();
                if(node->left && !vis[node->left]) q.push(node->left);
                if(node->right && !vis[node->right]) q.push(node->right);
                if(par.find(node)!=par.end() && !vis[par[node]]) q.push(par[node]);
            }
        }
        
        return dist-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
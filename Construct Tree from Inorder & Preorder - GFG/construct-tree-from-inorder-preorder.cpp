//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* solve(int preorder[],int inorder[],int prel,int prer,int inl,int inr){
        if(prel>prer) return NULL;
        Node* node=new Node(preorder[prel]);
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
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        return solve(preorder,inorder,0,n-1,0,n-1);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
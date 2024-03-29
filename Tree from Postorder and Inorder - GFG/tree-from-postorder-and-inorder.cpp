//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* solve(int postorder[], int inorder[],int postl,int postr,int inl,int inr){
        if(postl>postr) return NULL;
        Node* node=new Node(postorder[postr]);
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

Node *buildTree(int inorder[], int postorder[], int n) {
    return solve(postorder,inorder,0,n-1,0,n-1);
}

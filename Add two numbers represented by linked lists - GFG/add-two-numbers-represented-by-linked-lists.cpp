//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head){
        Node *cur=head,*last=NULL;
        while(cur){
            Node *nxt=cur->next;
            cur->next=last;
            last=cur;
            cur=nxt;
        }
        return last;
    }
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        Node *dummy=new Node(0);
        Node *p=dummy;
        int c=0;
        l1=reverse(l1);
        l2=reverse(l2);
        while(l1 || l2){
            int val=0;
            if(l1){
                val+=l1->data;
                l1=l1->next;
            }
            if(l2){
                val+=l2->data;
                l2=l2->next;
            }
            val+=c;
            
            c=val/10;
            val%=10;
            p->next=new Node(val);
            p=p->next;
        }
        while(c>0){
            
            p->next=new Node(c%10);
            c=c/10;
            p=p->next;
        }
        return reverse(dummy->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
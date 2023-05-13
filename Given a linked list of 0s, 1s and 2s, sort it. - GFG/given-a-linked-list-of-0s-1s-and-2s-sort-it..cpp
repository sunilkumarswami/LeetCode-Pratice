//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        if(!head || !head->next) return head;
        Node *zero=NULL,*stZero=NULL,*one=NULL,*stOne=NULL,*two=NULL,*stTwo=NULL,
        *p=head;
        while(p){
            if(p->data==0){
                if(!stZero){
                    stZero=p;
                    zero=p;
                }
                else{
                    zero->next=p;
                    zero=zero->next;
                }
            }
            else if(p->data==1){
                if(!stOne){
                    stOne=p;
                    one=p;
                }
                else{
                    one->next=p;
                    one=one->next;
                }
            }
            else{
                if(!stTwo){
                    stTwo=p;
                    two=p;
                }
                else{
                    two->next=p;
                    two=two->next;
                }
            }
            p=p->next;
        }
        Node *start=new Node(0);
        p=start;
        if(stZero){
            p->next=stZero;
            p=zero;
            zero->next=NULL;
        }
        if(stOne){
            p->next=stOne;
            p=one;
            one->next=NULL;
        }
        if(stTwo){
            p->next=stTwo;
            p=two;
            two->next=NULL;
        }
        return start->next;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
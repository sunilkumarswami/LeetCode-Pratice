//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};

void sort(Node **head);


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends


/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function
Node* merge(Node* h1,Node* h2){
        Node* start=new Node(0);
        Node *p=start;
        while(h1 && h2){
            if(h1->data<=h2->data){
                p->next=new Node(h1->data);
                h1=h1->next;
                p=p->next;
            }
            else{
                p->next=new Node(h2->data);
                h2=h2->next;
                p=p->next;
            }
        }
        while(h1){
            p->next=new Node(h1->data);
            h1=h1->next;
                p=p->next;
        }
        while(h2!=NULL){
            p->next=new Node(h2->data);
            h2=h2->next;
                p=p->next;
        }
        return start->next;
    }
    Node* divide(Node* head){
        if(!head || !head->next) return head;
        Node* slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *head2=slow->next;
        slow->next=NULL;
        head=divide(head);
        head2=divide(head2);
        return merge(head,head2);
    }
void sort(Node **head)
{

      *head=divide(*head);
}
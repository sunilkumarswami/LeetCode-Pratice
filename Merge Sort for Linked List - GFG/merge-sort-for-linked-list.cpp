//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
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
    Node* mergeSort(Node* head) {
        // your code here
        return divide(head);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
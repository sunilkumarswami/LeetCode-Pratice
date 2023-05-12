//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include<vector>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node *last,Node * cur){
        Node *nxt;
        while(cur!=NULL){
            nxt=cur->next;
            cur->next=last;
            last=cur;
            cur=nxt;
        }
        return last;
    }
    bool isPalindrome(Node *head)
    {
        if(head==NULL || head->next==NULL) return true;
        Node *slow=head,*fast=head,*temp=head;
        int cnt=0;
        while(fast->next!=NULL && fast->next->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
            // cnt++;
        }
        slow->next=reverse(NULL,slow->next);
        
        fast=head,slow=slow->next;
        while(slow!=NULL){
            if(fast->data!=slow->data) return false;
            fast=fast->next;
            slow=slow->next;
           
        }
        return true;  
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
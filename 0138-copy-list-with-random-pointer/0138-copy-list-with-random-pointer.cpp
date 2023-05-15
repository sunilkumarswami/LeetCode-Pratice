/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *p=head;
        while(p){
            Node *q=p->next;
            p->next=new Node(p->val);
            p->next->next=q;
            p=q;
        }
        p=head;
        while(p){
            Node *q=p->next;
            if(p->random==NULL) q->random=NULL;
            else{
                q->random=p->random->next;
            }
            p=q->next;
        }
        Node *h1=head,*h2=head->next,*newHead=head->next,*oldHead=h1;
        p=h2->next;
        while(p){
            h1->next=p;
            p=p->next;
            h2->next=p;
            p=p->next;
            h1=h1->next;
            h2=h2->next;
        }
        h1->next=NULL;
        
        return newHead;
    }
};
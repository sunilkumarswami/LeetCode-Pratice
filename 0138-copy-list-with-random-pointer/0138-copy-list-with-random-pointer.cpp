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
        if(head==NULL) return head;
        Node *newHead=new Node(head->val);
        unordered_map<Node*,Node*> mp;
        mp[head]=newHead;
        Node *p=head,*q=newHead;
        while(p->next){
            q->next=new Node(p->next->val);
            mp[p]=q;
            p=p->next;
            q=q->next;
            mp[p]=q;
        }
        p=head,q=newHead;
        while(p){
            if(p->random==NULL) q->random=NULL;
            else q->random=mp[p->random];
            p=p->next;
            q=q->next;
        }
        return newHead;
    }
};
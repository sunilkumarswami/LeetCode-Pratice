/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* h1,ListNode* h2){
        ListNode start(0);
        ListNode *p=&start;
        while(h1!=NULL && h2!=NULL){
            if(h1->val<=h2->val){
                p->next=h1;
                h1=h1->next;
            }
            else{
                p->next=h2;
                h2=h2->next;
            }
            p=p->next;
        }
        if(h1!=NULL){
            p->next=h1;
            h1=h1->next;
        }
        if(h2!=NULL){
            p->next=h2;
            h2=h2->next;
        }
        return start.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow=head,*fast=head,*temp=head;
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        // ListNode *mid=slow->next;
        temp->next=NULL;
        ListNode *left=sortList(head);
        ListNode* right=sortList(slow);
        return merge(left,right);
    }
};
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
        ListNode* start=new ListNode();
        ListNode *p=start;
        while(h1 && h2){
            if(h1->val<=h2->val){
                p->next=new ListNode(h1->val);
                h1=h1->next;
                p=p->next;
            }
            else{
                p->next=new ListNode(h2->val);
                h2=h2->next;
                p=p->next;
            }
        }
        while(h1){
            p->next=new ListNode(h1->val);
            h1=h1->next;
                p=p->next;
        }
        while(h2!=NULL){
            p->next=new ListNode(h2->val);
            h2=h2->next;
                p=p->next;
        }
        return start->next;
    }
    ListNode* divide(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* slow=head,*fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head2=slow->next;
        slow->next=NULL;
        head=divide(head);
        head2=divide(head2);
        return merge(head,head2);
    }
    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};
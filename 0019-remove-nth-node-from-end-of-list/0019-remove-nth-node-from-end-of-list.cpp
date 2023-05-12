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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || (head->next==NULL && n==1)) return NULL;
        ListNode *p=head;
        int total=0;
    while(p!=NULL){
        p=p->next;
        total++;
    }
    if(total==n) return head->next;
    total=total-n-1;
    p=head;
    while(total>0){
        p=p->next;
        total--;
    }
    p->next=p->next->next;
    return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        ListNode *p=headA;
        while(p){
            p=p->next;
            n++;
        }
        p=headB;
        while(p){
            p=p->next;
            m++;
        }
        if(m>n)
        return getIntersectionNode(headB,headA);
        ListNode *h1=headA,*h2=headB;
        while(h1 && h2){
            h1=h1->next;
            h2=h2->next;
        }
        if(!h2){
            h2=headA;
        }
        while(h1 && h2){
            if(h1==h2) return h1;
            h1=h1->next;
            h2=h2->next;
        }
        if(!h1) h1=headB;
        while(h1 && h2){
            if(h1==h2) return h1;
            h1=h1->next;
            h2=h2->next;
        }
        
        return NULL;
    }
};
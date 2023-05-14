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
        
        ListNode *h1=headA,*h2=headB;
        while(h1 && h2){
            h1=h1->next;
            h2=h2->next;
        }
        h1=(h1==NULL)?headB:h1;
        h2=(h2==NULL)?headA:h2;
        while(h1 && h2){
            if(h1==h2) return h1;
            h1=h1->next;
            h2=h2->next;
        }
        h1=(h1==NULL)?headB:h1;
        h2=(h2==NULL)?headA:h2;
        while(h1 && h2){
            if(h1==h2) return h1;
            h1=h1->next;
            h2=h2->next;
        }
        
        return NULL;
    }
};
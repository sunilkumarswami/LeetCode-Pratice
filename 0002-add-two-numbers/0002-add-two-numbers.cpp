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
    ListNode* reverse(ListNode* head){
        ListNode *cur=head,*last=NULL;
        while(cur){
            ListNode *nxt=cur->next;
            cur->next=last;
            last=cur;
            cur=nxt;
        }
        return last;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode();
        ListNode *p=dummy;
        int c=0;
        while(l1 || l2){
            int val=0;
            if(l1){
                val+=l1->val;
                l1=l1->next;
            }
            if(l2){
                val+=l2->val;
                l2=l2->next;
            }
            val+=c;
            
            c=val/10;
            val%=10;
            p->next=new ListNode(val);
            p=p->next;
        }
        while(c>0){
            
            p->next=new ListNode(c%10);
            c=c/10;
            p=p->next;
        }
        return dummy->next;
        // return reverse(dummy->next);
        
    }
};
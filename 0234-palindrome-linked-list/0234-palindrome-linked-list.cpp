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
    ListNode* reverse(ListNode *last,ListNode * cur){
        ListNode *nxt;
        while(cur!=NULL){
            nxt=cur->next;
            cur->next=last;
            last=cur;
            cur=nxt;
        }
        return last;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *slow=head,*fast=head,*temp=head;
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
            if(fast->val!=slow->val) return false;
            fast=fast->next;
            slow=slow->next;
           
        }
        return true;  
    }
};
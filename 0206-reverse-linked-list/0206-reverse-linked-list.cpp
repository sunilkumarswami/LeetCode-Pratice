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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur=head,*last=NULL,*nxt;
        while(cur!=NULL){
            nxt=cur->next;
            cur->next=last;
            last=cur;
            cur=nxt;
        }
        return last;
    }
};
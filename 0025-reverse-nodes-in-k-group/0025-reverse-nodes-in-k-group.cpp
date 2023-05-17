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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode *pre=dummy,*cur=head,*nex=cur->next,*p=head;
        int cnt=0;
        while(p){
            p=p->next;
            cnt++;
        }
        while(cnt>=k){
            int x=k-1;
            while(x--){
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            cnt-=k;
            if(cnt<k) break;
            pre=cur;
            cur=nex;
            nex=nex->next;
        }
        return dummy->next;
    }
};
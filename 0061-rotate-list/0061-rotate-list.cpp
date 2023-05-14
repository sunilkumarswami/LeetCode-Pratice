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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* p=head;
        int cnt=0;
        while(p){
            p=p->next;
            cnt++;
        }
        k=k%cnt;
        k=cnt-k;
        if(cnt==k || k==0) return head;
        
        p=head;
        while(k>1){
            p=p->next;
            k--;
        }
        ListNode *newHead=p->next;
        p->next=NULL;
        ListNode *q=newHead;
        while(q->next) 
            q=q->next;
            
        q->next=head;
        return newHead;
    }
};
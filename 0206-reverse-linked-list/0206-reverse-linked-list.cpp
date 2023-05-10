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
    struct ListNode* solve(struct ListNode *cur,struct ListNode *last){
        if(cur==NULL) return last;
        ListNode *nxt=cur->next;
        cur->next=last;
        return solve(nxt,cur);
    }
    ListNode* reverseList(ListNode* head) {
        return solve(head,NULL);
    }
};
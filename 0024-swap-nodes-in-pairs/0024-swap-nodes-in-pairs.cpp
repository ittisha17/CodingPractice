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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*res=head->next;
        while(curr!=NULL && curr->next!=NULL)
        {
            ListNode*future=curr->next->next;
            ListNode*nxt=curr->next;

            curr->next=nxt->next;
            nxt->next=curr;

            if(prev!=NULL)
             prev->next=nxt;
            prev=curr;
            curr=future;
        }
        return res;
    }
};
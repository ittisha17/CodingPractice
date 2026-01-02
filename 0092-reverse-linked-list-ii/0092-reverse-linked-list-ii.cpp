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

ListNode*reverse(ListNode*head)
{
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*future;
    while(curr!=NULL)
    {
        future=curr->next;
        curr->next=prev;
        prev=curr;
        curr=future;
    }
    return prev;
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*st=head;
        ListNode*prev=head;
        ListNode* en=head;
        int l=left;
        while(left>1)
        {   
            prev=st;
            st=st->next;
            left--;
        }
        while(right>1)
        {
            en=en->next;
            right--;
        }
        ListNode*rest=en->next;
        en->next=NULL;
        en=st;
        ListNode*res_head;
        if(prev!=st)
          prev->next=reverse(st);
        else
         res_head=reverse(st);
        en->next=rest;
        if(l==1) return res_head;
        return head;

    }
};
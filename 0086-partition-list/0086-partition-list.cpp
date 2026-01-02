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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode* res_head=NULL;
        ListNode*prev=NULL;
        ListNode*after_head=NULL;
        ListNode*after=NULL;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                if(res_head==NULL)
                 {prev=head;
                 res_head=head;
                 }
                else
                 {
                    prev->next=head;
                    prev=prev->next;
                 }
            }
            else
            {
              if(after_head==NULL)
              {
                after=head;
                after_head=head;
              }
              else
              {
                after->next=head;
                after=after->next;
              }
            }
            head=head->next;
        }
        if(after)
         after->next=NULL;
        if(prev==NULL)
          return after_head;
        prev->next=after_head;
        return res_head;

    }
};
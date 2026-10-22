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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*res_head=new ListNode(INT_MAX);
        ListNode*ptr=res_head;
        ListNode*curr=head;
        while(curr!=NULL)
        {   
            int cnt=0;
            while(curr!=NULL && curr->next!=NULL && curr->val==curr->next->val)
            { curr=curr->next;
              cnt++;
            }
            if(cnt==0)
             {ptr->next=new ListNode(curr->val);
             ptr=ptr->next;
             }
            curr=curr->next;
        }
      return res_head->next;
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*slow=head;
        ListNode*fast=head;

        ListNode*newHead;
        int i=0;
        while(i<n && fast!=NULL)
         {fast=fast->next;
          i++;
         }
        
        if(fast==NULL) //first node to be remove;
         { newHead=slow->next;
           slow->next=NULL;
           delete(slow);
           return newHead;
         }
        
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        //now slow points at node just before the node to be deleted
        ListNode*target=slow->next;
        slow->next=target->next;
        target->next=NULL;
        delete(target);
        return head;
         
    }
};
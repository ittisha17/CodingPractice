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

ListNode* reverse(ListNode*head)
{
    ListNode*curr=head;
    ListNode*future;
    ListNode*prev=NULL;
    while(curr)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*st=head;
        ListNode*end=head;

         ListNode*dummy=new ListNode(0);
         ListNode*connector;
        while(end)
        {  
            for(int i=0;i<k-1;i++)
             { end=end->next;
               if(!end)
               { connector->next=st;
                return dummy->next;
               }
             }
           ListNode*nxt=end->next;
           end->next=NULL;
           if(!dummy->next)
            dummy->next=reverse(st);
           else
            connector->next=reverse(st);
           connector=st;
           st=end=nxt;
        }
        return dummy->next;
         
       


    }
};
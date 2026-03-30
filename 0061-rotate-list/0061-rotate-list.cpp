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
        if(head==NULL || head->next==NULL || k==0)
         return head;
        int ln=0;
        ListNode*curr=head;
        while(curr)
        {
            ln++;
            curr=curr->next;
        }
        k=k%ln;
        if(k==0) return head; 
        int pos=ln-k;
        ListNode*end=head;
        for(int i=0;i<pos-1;i++)
         end=end->next;
        //end point at node tht should be new end
        ListNode*st=end->next;  //new head;
        end->next=NULL;

        ListNode*temp=st;
        while(temp->next)
         temp=temp->next;
        temp->next=head;
        return st;

    }
};
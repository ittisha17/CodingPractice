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
        if(head==NULL || head->next==NULL) return head;
        int ln=0;
        ListNode*curr=head;
        while(curr)
        {
            curr=curr->next;
            ln++;
        }
        k=k%ln;
        if(k==0) return head;
        int pos=ln-k; //kth node from end is n-k+1th node from start
        ListNode*prev;
        curr=head;
        while(pos)
        {
            prev=curr;
            curr=curr->next;
            pos--;
        }
        prev->next=NULL;
        ListNode*res=curr;
        while(curr!=NULL && curr->next!=NULL)
         curr=curr->next;
        curr->next=head;
        return res;
    }
};
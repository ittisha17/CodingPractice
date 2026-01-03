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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*h1=list1;
        ListNode*h2=list2;
        if(h1==NULL) return h2;
        if(h2==NULL) return h1;
        ListNode*res_head;
        ListNode* temp;
        if(h1->val<h2->val)
        {
            res_head=h1;
            temp=h1;
            h1=h1->next;
        }
        else
        {
            res_head=h2;
            temp=h2;
            h2=h2->next;
        }
        while(h1!=NULL && h2!=NULL)
        {
            if(h1->val<h2->val)
            {
                temp->next=h1;
                h1=h1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=h2;
                h2=h2->next;
                temp=temp->next;
            }
        }
        if(h1)
            temp->next=h1;
        if(h2)
           temp->next=h2;
        return res_head;

        }
};
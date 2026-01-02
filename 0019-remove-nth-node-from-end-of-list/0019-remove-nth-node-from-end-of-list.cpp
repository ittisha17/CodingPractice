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
        int len=0;
        ListNode*curr=head;
        while(curr)
        {    len++;
            curr=curr->next;
        }
        int beg_id=len-n+1;
        ListNode*prev=NULL;
        ListNode*node=head;
        while(beg_id>1)
        {
            prev=node;
            node=node->next;
            beg_id--;
        }
        if(prev==NULL) //first node to be deleted
        { ListNode*res=node->next;
          node->next=NULL;
          delete(node);
          return res;
        }
        else
        {
            prev->next=node->next;
            node->next=NULL;
            delete(node);
        }
        return head;

    }
};
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
struct myCmp
{
    bool operator()(ListNode* n1,ListNode*n2)
    {
        return n1->val>n2->val; //min heap
    }
} ;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res=new ListNode(0);
        ListNode*curr=res;
        priority_queue<ListNode*,vector<ListNode*>,myCmp> pq;
        for(int i=0;i<lists.size();i++)
         { if(lists[i]!=NULL)
            pq.push(lists[i]);
         }
        while(!pq.empty())
        {
            ListNode*temp=pq.top();
            pq.pop();
            if(temp->next!=NULL)
             pq.push(temp->next);
            temp->next=NULL;
            curr->next=temp;
            curr=curr->next;
        }
        return res->next;

        
    }
};
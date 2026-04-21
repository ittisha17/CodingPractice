/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //even index->old
        //odd index->new
        if(head==NULL) return NULL;
        Node*curr=head;
        while(curr)
        {
            Node*nn=new Node(curr->val);
            Node*nxt=curr->next;
           curr->next=nn;
           nn->next=nxt;
           curr=nxt;
        }

        Node*nh=head->next;
        curr=head;
        //fix the random pointers
        while(curr && curr->next)
        {   
            if(curr->random)
               curr->next->random=curr->random->next;
            else
             curr->next->random=NULL;
            curr=curr->next->next;
        }

        curr=head;
        while(curr && curr->next)
        {
            Node*copy=curr->next;
            curr->next=copy->next;
            if(copy->next)
             copy->next=copy->next->next;
            curr=curr->next;

        }
        return nh;

    }
};
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
Node*reverse(Node*head)
{
    Node*curr,*prev,*future;
    curr=head;
    prev=NULL;
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
    struct Node* modifyTheList(struct Node* head) {
        // add code here.
        if(head==NULL || head->next==NULL) return head;
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node*res_head=new Node(0);
        Node* h2=slow->next;
        slow->next=NULL;
        h2=reverse(h2);
        
        Node*ptr1=head;
        Node*ptr2=h2;
        
        Node*curr=res_head;
        while(ptr1 && ptr2)
        {
            curr->next=new Node(ptr2->data-ptr1->data);
            swap(ptr1->data,ptr2->data);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            curr=curr->next;
        }
        if(ptr1)
         {curr->next=ptr1; //in case odd elements so 1 extra elemnt in head
          curr=curr->next;
         }
         h2=reverse(h2);
        curr->next=h2; 
        return res_head->next;
        
        
        
        
    }
};
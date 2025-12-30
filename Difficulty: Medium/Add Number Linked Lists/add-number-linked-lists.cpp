/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
Node* reverse(Node*head)
{
    Node*prev=NULL;
    Node*curr=head;
    Node*future;
    while(curr!=NULL)
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
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        Node *h1=head1;
        while(h1!=NULL && h1->data==0)
          h1=h1=h1->next;
         h1=reverse(h1);
         
        Node *h2=head2;
        while(h2!=NULL && h2->data==0)
          h2=h2->next;
        h2=reverse(h2); 
        Node* res_h=new Node(0);
        Node*ptr=res_h;
        int carry=0;
        
        while(h1!=NULL && h2!=NULL)
        {
            int sum=h1->data+h2->data+carry;
            int num=sum%10;
            carry=sum/10;
            Node*nn=new Node(num);
            ptr->next=nn;
            ptr=ptr->next;
            h1=h1->next;
            h2=h2->next;
        }
        while(h1!=NULL)
        { int sum=h1->data+carry;
            int num=sum%10;
            carry=sum/10;
            Node*nn=new Node(num);
            ptr->next=nn;
            ptr=ptr->next;
            h1=h1->next;
        }
        while(h2!=NULL)
        {
            int sum=h2->data+carry;
            int num=sum%10;
            carry=sum/10;
            Node*nn=new Node(num);
            ptr->next=nn;
            ptr=ptr->next;
            h2=h2->next;
        }
        if(carry!=0)
         ptr->next=new Node(carry);
        res_h=reverse(res_h->next);
        
        return res_h;
        
    }
};
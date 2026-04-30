/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
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
    Node* sort(Node* head) {
        // Code here
        if(head==NULL || head->next==NULL) return head;
        
        Node*res_head=head;
        
        Node*list1_inc=new Node(0);
        Node*list2_dec=new Node(0);
        Node*itr1=list1_inc;
        Node*itr2=list2_dec;
        
        int cnt=0;
        
        Node*curr=head;
        while(curr)
        {   
            Node*nxt=curr->next;
            if(cnt%2==0) //even
            {
                itr1->next=curr;
                curr->next=NULL;
                itr1=curr;
            }
            else
            {
                itr2->next=curr;
                curr->next=NULL;
                itr2=curr;
            }
            curr=nxt;
            cnt++;
        }
         
        Node*ptr=list2_dec;
        list2_dec=ptr->next;
        ptr->next=NULL;
        delete(ptr);
        list2_dec=reverse(list2_dec);
        itr1->next=list2_dec;
        return list1_inc->next;
    }
};
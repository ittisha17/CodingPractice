/* Node structure

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

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        // Your Code here
        Node*even_head=new Node(0);
        Node*odd_head=new Node(0);
        Node*odd_ptr=odd_head;
        Node*even_ptr=even_head;
        Node*curr=head;
        int cnt=1;
        while(curr) 
        {   
            Node*nxt=curr->next;
            curr->next=NULL;
            if(cnt%2==1) //odd
            {
                odd_ptr->next=curr;
                odd_ptr=odd_ptr->next;
            }
            else
            {
                even_ptr->next=curr;
                even_ptr=even_ptr->next;
            }
            curr=nxt;
            cnt++;
        }
        
        head=odd_head->next;
        odd_head->next=NULL;
        delete(odd_head);
        
        odd_ptr->next=even_head->next;
        even_head->next=NULL;
        delete(even_head);
        // return odd_head;
    }
};
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node *addPolynomial(Node *head1, Node *head2) {
        // Your code here
        Node*res_head=new Node(0,0);
        Node*ptr=res_head;
        Node*h1=head1;
        Node*h2=head2;
        while(h1 && h2)
        {
            if(h1->pow>h2->pow)
            {
                ptr->next=h1;
                Node*nxt=h1->next;
                h1->next=NULL;
                h1=nxt;
                ptr=ptr->next;
               
            }
            else if(h2->pow>h1->pow)
            {
                ptr->next=h2;
                Node*nxt=h2->next;
                h2->next=NULL;
                h2=nxt;
                ptr=ptr->next;
            }
            else //same power
            {
                ptr->next=new Node(h1->coeff+h2->coeff,h1->pow);
                h1=h1->next;
                h2=h2->next;
                ptr=ptr->next;
            }
        }
        
        if(h1)
         ptr->next=h1;
        if(h2)
         ptr->next=h2;
        return res_head->next;
        
    }
};
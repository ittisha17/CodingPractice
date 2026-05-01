/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* zigZag(Node* head) {
        Node*curr=head;
        int cnt=0;  //basically elements at odd position needs to be greater than its neigbours
        while(curr)
        {
            if(cnt%2==0) //even;
             {
                 if(curr->next!=NULL)
                 {
                     if(curr->next->data<curr->data)
                      swap(curr->next->data,curr->data);
                 }
             }
             else //odd pos
             {
                  if(curr->next!=NULL)
                 {
                     if(curr->next->data>curr->data)
                      swap(curr->next->data,curr->data);
                 }
             }
             cnt++;
             curr=curr->next;
        }
        return head;
    }
   
};
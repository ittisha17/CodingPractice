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
class Solution {
  public:
    Node* makeUnion(Node* head1, Node* head2) {
        // code here
        if(head1==NULL)
          return head2;
        if(head2==NULL)
          return head1;
        
        vector<Node*>res;
        Node*itr1=head1;
        Node*end=NULL;
        set<int>st;
        while(itr1!=NULL)
        {   
            if(st.find(itr1->data)==st.end())
            {
                res.push_back(new Node(itr1->data));
            }
            st.insert(itr1->data);
            itr1=itr1->next;
        }
        
        Node*itr2=head2;
        while(itr2!=NULL)
        {   
            if(st.find(itr2->data)==st.end())
            {
                res.push_back(new Node(itr2->data));
            }
            st.insert(itr2->data);
            itr2=itr2->next;
        }
        
        Node*res_head=new Node(0);
        Node*temp=res_head;
        for(int i=0;i<res.size();i++)
        {
            temp->next=res[i];
            temp=temp->next;
        }
        return res_head->next;
    }
};
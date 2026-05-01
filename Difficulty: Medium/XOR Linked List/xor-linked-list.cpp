/*
Structure of linked list is as
struct Node
{
    int data;
    struct Node* npx;

    Node(int x){
        data = x;
        npx = NULL;
    }
};

Utility function to get XOR of two Struct Node pointer
use this function to get XOR of two pointers
struct Node* XOR (struct Node *a, struct Node *b)
{
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}
*/

// function should insert the data to the front of the list
struct Node *insert(struct Node *head, int data) {
    // Code here
    Node*nn=new Node(data);
    if(head==NULL) return nn;
    nn->npx=XOR(head,NULL);
    head->npx=XOR(head->npx,XOR(nn,NULL));
    return nn;
}

vector<int> getList(struct Node *head) {

    vector<int> res;
    Node*curr=head;
    Node*prev=NULL;
    while(curr)
    {
        res.push_back(curr->data);
        Node*next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
    return res;
    // Code here
}
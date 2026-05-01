/*
class NodeLL {
  public:
    int data;
    NodeLL *next;

    NodeLL(int x) {
        data = x;
        next = NULL;
    }
};
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/


Node* Construct(int id,vector<int>&nodes,int n)
{
    if(id>=n) return NULL;
    Node*root=new Node(nodes[id]);
    root->left=Construct(2*id+1,nodes,n);
    root->right=Construct(2*id+2,nodes,n);
    return root;
}

class Solution {
  public:
    Node *linkedListToBinaryTree(NodeLL *head) {
        // code here
        vector<int> nodes;
        NodeLL*curr=head;
        while(curr)
        {
            nodes.push_back(curr->data);
            curr=curr->next;
        }
        
        int id=0;
        int n=nodes.size();
        return Construct(id,nodes,n);
    }
};
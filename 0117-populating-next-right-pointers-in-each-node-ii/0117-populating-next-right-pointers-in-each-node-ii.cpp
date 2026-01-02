/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n-1;i++)
             {
                Node*nn=q.front();
                q.pop();
                nn->next=q.front();
                if(nn->left!=NULL) q.push(nn->left);
                if(nn->right!=NULL) q.push(nn->right);
               
             }
             Node*end=q.front();
             q.pop();
             if(end->left!=NULL) q.push(end->left);
             if(end->right!=NULL) q.push(end->right);
            
             end->next=NULL;
        }
        return root;

    }
};
/*
 A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    /* Function to print nodes of extreme corners
    of each level in alternate order */
    vector<int> extremeNodes(Node* root) {
        // Your code here
        int var=0;
        vector<int>res;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {   
                Node*nd=q.front();
                q.pop();
                if(var==0 && i==n-1) //rightmost
                  res.push_back(nd->data);
                else if(var==1 && i==0) //leftmost
                 res.push_back(nd->data);
                
                if(nd->left!=NULL)
                 q.push(nd->left);
                if(nd->right)
                 q.push(nd->right);
            }
             var=var^1;
        }
        return res;
        
    }
};
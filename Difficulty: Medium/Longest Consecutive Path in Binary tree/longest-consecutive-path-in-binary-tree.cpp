/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/


void Longest_path(Node*root,int&ln,int curr_ln)
{
    if(!root) return;
    
    ln=max(ln,curr_ln);
    
    if(root->left==NULL && root->right==NULL)
      return;
    if(root->left!=NULL)
    {if(root->left->data-root->data==1)
      {
          Longest_path(root->left,ln,curr_ln+1);
      }
    else
      {
      Longest_path(root->left,ln,1);}
    }
      
    if(root->right!=NULL)
    {if(root->right->data-root->data==1)
      {
      Longest_path(root->right,ln,curr_ln+1);}
    else
    { 
      Longest_path(root->right,ln,1);
    }
    }
     
    
    
}
class Solution {
  public:
    int longestConsecutive(Node* root) {
        // code here
        int mx_ln=0;
        int curr_ln=1;
        
        Longest_path(root,mx_ln,curr_ln);
        if(mx_ln==1)
         return -1;
        else
         return mx_ln;
      
        
    }
};
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */


void Calc(Node*root,int&sum,int curr_val)
{
    if(root==NULL)
     return;
    curr_val=curr_val*10+root->data;
    if(root->left==NULL && root->right==NULL)
     {
         sum+=curr_val;
     }
     Calc(root->left,sum,curr_val);
     Calc(root->right,sum,curr_val);
     curr_val=curr_val/10;
}
class Solution {
  public:
    int treePathsSum(Node *root) {
        // code here.
        int sum=0;
        int curr_val=0;
        Calc(root,sum,curr_val);
        return sum;
        
    }
};
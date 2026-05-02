/*The Node is defined as follows:
struct Node
{
    int data ;
    struct Node * left, * right ;
};
*/

int leaves(Node*root,int k,vector<int>&res)
{
    if(root==NULL)
     return 0;
    if(root->left==NULL && root->right==NULL)
     return 1;
    int left=leaves(root->left,k,res);
    int right=leaves(root->right,k,res);
    int total=left+right;
    if(total==k)
      res.push_back(root->data); 
      
    return left+right;
}




class Solution {
  public:
    /*You are required to complete below method */

    vector<int> btWithKleaves(Node *ptr, int k) {
        // your code here.
        vector<int> res;
        leaves(ptr,k,res);
        if(res.size()==0)
         return {-1};
        return res;
        
        
    }
};
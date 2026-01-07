/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false


pair<bool,int> SumTree(Node*root)
{
    if(root==NULL) 
     return {true,0};
    if(root->left==NULL && root->right==NULL)
      return{true,root->data};
    auto left=SumTree(root->left);
    auto right=SumTree(root->right);
    if(left.first && right.first && root->data==left.second+right.second)
      return{true,left.second+right.second+root->data};
    return{false,0};
    
    
}
class Solution {
  public:
    bool isSumTree(Node* root) {
        // Your code here
        if(root==NULL) return true;
        return(SumTree(root).first);
         
    }
};
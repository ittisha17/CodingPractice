/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
void Solve(Node*root,vector<vector<int>>&res,vector<int>&temp)
{
    if(root==NULL)return;
    temp.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
     {
         res.push_back(temp);
         
     }
     Solve(root->left,res,temp);
 
     Solve(root->right,res,temp);
         temp.pop_back();
}


class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> res;
        vector<int> temp;
        Solve(root,res,temp);
        return res;
    }
};
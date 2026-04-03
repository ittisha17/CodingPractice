/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
TreeNode* Build(int st,int end,int &idx,vector<int>&inorder,vector<int>&postorder)
{
    if(st>end)
     return NULL;
    int val=postorder[idx];
    int inord_id=-1;
    for(int i=st;i<=end;i++)
    {
        if(inorder[i]==val)
         {
            inord_id=i;
            break;
         }
    }
    TreeNode* root=new TreeNode(val);
    idx--;
    root->right=Build(inord_id+1,end,idx,inorder,postorder);
    root->left=Build(st,inord_id-1,idx,inorder,postorder);

    return root;  
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int st=0;
        int end=n-1;
        int id=n-1;
        return Build(st,end,id,inorder,postorder);
    }
};
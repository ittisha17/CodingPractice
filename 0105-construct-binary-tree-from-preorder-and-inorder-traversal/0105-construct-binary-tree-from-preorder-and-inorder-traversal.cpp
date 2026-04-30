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
TreeNode* Construct (int &idx,int st,int end,vector<int>&preorder,vector<int>&inorder)
{
    if(st>end) return NULL;
   
    TreeNode*root=new TreeNode(preorder[idx]);
    int value=root->val;
    int index=-1;
    for(int i=st;i<=end;i++)
    {
        if(value==inorder[i])
        {
            index=i;
            break;
        }
    }
    idx++;
    root->left=Construct(idx,st,index-1,preorder,inorder);
    root->right=Construct(idx,index+1,end,preorder,inorder);

    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        int st=0;
        int end=inorder.size()-1;
        return Construct(idx,st,end,preorder,inorder);
    }
};

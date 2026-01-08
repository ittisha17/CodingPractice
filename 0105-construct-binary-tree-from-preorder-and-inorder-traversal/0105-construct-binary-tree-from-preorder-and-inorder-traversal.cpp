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
TreeNode* construct(int &id,int l,int h,vector<int>&preorder,vector<int>&inorder,int n)
{
    if(l>h) return NULL;
    int rt_val=preorder[id];
    id++;
    int rt_id;
    for(int i=l;i<=h;i++)
     {
        if(inorder[i]==rt_val)
         {
            rt_id=i;
            break;
         }
     }
     TreeNode*root=new TreeNode(rt_val);
     root->left=construct(id,l,rt_id-1,preorder,inorder,n);
     root->right=construct(id,rt_id+1,h,preorder,inorder,n);
     return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_idx=0;
        TreeNode*root;
        int l=0;
        int n=preorder.size();
        int h=preorder.size()-1;
        root=construct(pre_idx,l,h,preorder,inorder,n);
        return root;
    }
};
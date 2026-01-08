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
TreeNode* construct(int&id,int l,int h,int n,vector<int>&inorder,vector<int>&postorder)
{
    if(l>h) return NULL;
    int rt_val=postorder[id--];
    TreeNode*root=new TreeNode(rt_val);
    int rt_id;
    for(int i=l;i<=h;i++)
    {  if(inorder[i]==rt_val)
        { rt_id=i;
         break;
        }
    }

    
    root->right=construct(id,rt_id+1,h,n,inorder,postorder);
    root->left=construct(id,l,rt_id-1,n,inorder,postorder);
    return root;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int h=n-1;
        int l=0;
        int pst_id=h;
        TreeNode* root=construct(pst_id,l,h,n,inorder,postorder);
        return root;
}
};
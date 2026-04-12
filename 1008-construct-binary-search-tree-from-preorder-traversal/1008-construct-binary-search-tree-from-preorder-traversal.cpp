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

TreeNode* construct(vector<int>&preorder,int st,int end)
{  
    if(st>end) return NULL;
    TreeNode*root=new TreeNode(preorder[st]);
    if(st<end)
   {
     int idx=-1;
     for(int i=st+1;i<=end;i++)
     {
        if(preorder[i]>root->val) 
         {
            idx=i;
            break;
         }
     }
     if(idx == -1) idx = end + 1;
     root->left=construct(preorder,st+1,idx-1);
     root->right=construct(preorder,idx,end);
   }
   return root;
    

  
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        int st=0;
        int end=n-1;
        return construct(preorder,st,end); 
    }
};
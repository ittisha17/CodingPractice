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

void convert(TreeNode*root,vector<TreeNode*> &vc)
{  if(root==NULL) return;
    vc.push_back(root);
    convert(root->left,vc);
    convert(root->right,vc);
}


class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        vector<TreeNode*> vc;
        convert(root,vc);
        for(int i=0;i<vc.size()-1;i++)
        {
           TreeNode*nn=vc[i];
           nn->left=NULL;
           nn->right=vc[i+1];
        }
        return;
    }
};
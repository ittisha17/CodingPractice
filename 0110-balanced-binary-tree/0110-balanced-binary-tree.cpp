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

int height(TreeNode*root,bool &flag)
{
    if(!root) 
     return 0;
    int lh=height(root->left,flag)+1;
    int rh=height(root->right,flag)+1;
    if(abs(lh-rh)>1) 
     flag=false;
    return max(lh,rh);
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        height(root,flag);
        return flag;
    }
};
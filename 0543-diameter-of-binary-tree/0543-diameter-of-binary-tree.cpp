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


int mxDepth(TreeNode*root,int &diameter)
{
    if(!root) return 0;
    int lh=mxDepth(root->left,diameter);
    int rh=mxDepth(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);

} 
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        mxDepth(root,diameter);
        return diameter;
    }
};
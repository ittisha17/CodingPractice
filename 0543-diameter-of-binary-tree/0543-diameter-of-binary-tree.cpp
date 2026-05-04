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
int height(TreeNode*root,int &mx_h)
{
    if(!root) return 0;
    int left=height(root->left,mx_h);
    int right=height(root->right,mx_h);
    mx_h=max(mx_h,left +right);
    return 1+max(left,right);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int mx_h=0;
        height(root,mx_h);
        return mx_h;
    }
};
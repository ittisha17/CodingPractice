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

int height(TreeNode*root,int&diameter)
{   
    if(!root)
      return -1;
    int l=max(0,height(root->left,diameter));
    int r=max(0,height(root->right,diameter));
    diameter=max(diameter,l+r);
    return 1+max(l,r);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
     int diameter=-1;
     height(root,diameter);
     return diameter;
    }
};
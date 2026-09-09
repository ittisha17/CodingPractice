/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root==p || root==q)
         return root;
        TreeNode*l1=lowestCommonAncestor(root->left,p,q);
        TreeNode*l2=lowestCommonAncestor(root->right,p,q);
        if(l1 && l2)
         return root;
        else if(l1)
         return l1;
        else
         return l2;
        
    }
};
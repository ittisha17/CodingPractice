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

void traverse(TreeNode*root,int &k,int&val)
{
    if(root)
    {
        traverse(root->left,k,val);
        k--;
        if(k==0)
        {val=root->val;
        return;}
        traverse(root->right,k,val);
    }
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        int val=-1;
        traverse(root,k,val);
        return val;

    }
};
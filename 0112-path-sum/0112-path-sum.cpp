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
bool check(TreeNode*root,int target,int sum)
{
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL)
     {
        if(sum+root->val==target)
         return true;
     }
    sum+=root->val;
    return(check(root->left,target,sum) || check(root->right,target,sum));
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return check(root,targetSum,sum);
    }
};
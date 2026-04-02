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

int Max_path(TreeNode*root,int &mx_sum)
{
    if(!root)
     return 0;

    int v1=max(0,Max_path(root->left,mx_sum));
    int v2=max(0,Max_path(root->right,mx_sum));
    
    int v3=v1+v2+root->val;
    mx_sum=max(mx_sum,v3);

    return root->val+max(v1,v2);
     
}

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx_sum=INT_MIN;
        Max_path(root,mx_sum);
        return mx_sum;
    }
};
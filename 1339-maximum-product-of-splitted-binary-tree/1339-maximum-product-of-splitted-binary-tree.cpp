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
void totalSum(TreeNode*root,long long &sum)
{
   if(root==NULL) return ;
   sum+=root->val;
   totalSum(root->left,sum);
   totalSum(root->right,sum);
}


long long eval(TreeNode* root, long long &ans, long long total)
{
    if (root == NULL) return 0;

    long long left = eval(root->left, ans, total);
    long long right = eval(root->right, ans, total);

    long long curr = left + right + root->val;   // subtree sum
    ans = max(ans, curr * (total - curr));

    return curr;
}

class Solution {
public:
    int maxProduct(TreeNode* root) {
        long long ans=0;
        long long curr=0;
        long long sum=0;
        totalSum(root,sum);
        eval(root,ans,sum);
        return ans%1000000007;
    }
};
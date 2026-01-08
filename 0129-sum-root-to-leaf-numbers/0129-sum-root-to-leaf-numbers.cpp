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
void eval(TreeNode*root,int &num,int &sum)
{
    if(root==NULL) return;
    num=num*10+root->val;
    if(root->left==NULL && root->right==NULL)
     sum+=num;
    eval(root->left,num,sum);
    eval(root->right,num,sum);
    num=num/10;


}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int num=0;
        eval(root,num,sum);
        return sum;
    }
};
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
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return -1;
        int mx_sum=INT_MIN;
        int level=-1;
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(!q.empty())
        {
            int n=q.size();
            int s=0;
            l++;
            for(int i=0;i<n;i++)
            {   
                TreeNode* nn=q.front();
                q.pop();
                s+=nn->val;
                if(nn->left!=NULL)
                 q.push(nn->left);
                if(nn->right!=NULL)
                 q.push(nn->right);
            }
            if(s>mx_sum)
             {
                mx_sum=s;
                level=l;
             }
            
        }

       return level;
    }
};
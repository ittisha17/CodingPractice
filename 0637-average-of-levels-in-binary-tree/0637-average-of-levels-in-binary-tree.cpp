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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        if(root==NULL) return res;
        while(!q.empty())
        {
            int n=q.size();
            double sum=0;
            for(int i=0;i<n;i++)
             { TreeNode*nn=q.front();
               q.pop();
               sum+=nn->val;
               if(nn->left!=NULL) q.push(nn->left);
               if(nn->right!=NULL) q.push(nn->right);
            }
            res.push_back(sum/n);
        }
        return res;
    }
};
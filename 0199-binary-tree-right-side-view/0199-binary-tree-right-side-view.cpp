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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int> res;
        if(root==NULL) return {};
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {   
                TreeNode* nn=q.front();
                if(i==n-1)
                 res.push_back(nn->val);
                q.pop();
                if(nn->left!=NULL)
                 q.push(nn->left);
                if(nn->right!=NULL)
                 q.push(nn->right);
            }
        }
        return res;


        
    }
};
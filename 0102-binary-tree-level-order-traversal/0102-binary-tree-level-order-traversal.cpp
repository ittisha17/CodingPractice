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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {   
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++)
            {TreeNode*nn=q.front();
            q.pop();
            temp.push_back(nn->val);
            if(nn->left!=NULL)
             q.push(nn->left);
            if(nn->right!=NULL)
             q.push(nn->right);
            }
            res.push_back(temp);
        }
        return res;

    }
};
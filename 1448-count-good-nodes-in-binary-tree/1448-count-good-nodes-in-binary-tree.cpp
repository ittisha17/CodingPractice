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
void traverseDfs(TreeNode*root,int &cnt,int curr_mx)
{  
    if(root==NULL) return;
   if(root->val>=curr_mx)
    {cnt++;
     curr_mx=root->val;
    }
    traverseDfs(root->left,cnt,curr_mx);
    traverseDfs(root->right,cnt,curr_mx);
    return;
}

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int curr_mx=INT_MIN;
        int cnt=0;
        traverseDfs(root,cnt,curr_mx);
        return cnt;

        
    }
};
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
        vector<int>ans;
if(!root) return ans;

queue<TreeNode*>Q;
Q.push(root); // level 0

while(!Q.empty()){
int currLevelSize = Q.size();
int n=Q.size();
while(currLevelSize--){
TreeNode* curr = Q.front();
 if(currLevelSize==0) //last elem
 ans.push_back(curr->val);
Q.pop();
//level.push_back(curr->val);
// explore it
if(curr->left) Q.push(curr->left);
if(curr->right)Q.push(curr->right);
}

}

return ans;
}
};
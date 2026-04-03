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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*,int>> st;
        st.push({root,0});
        while(!st.empty())
        {
            auto temp=st.top();
            if(!temp.first) 
            { st.pop();
             continue;
            } 
            if(temp.second==0)  //stae 0 explore left
            { 
               st.top().second++; //increment state to 1
               st.push({temp.first->left,0});  
            }
            else if(temp.second==1) //left child explored include current
            {
                res.push_back(temp.first->val);
                st.top().second++;
                st.push({temp.first->right,0});
            }
            else //state 2 left right explore now remove
            {
                 st.pop();
            }

        }
        return res;
        
    }
};
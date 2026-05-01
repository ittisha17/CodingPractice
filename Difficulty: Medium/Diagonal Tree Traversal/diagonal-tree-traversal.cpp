/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

void dfs(Node*root,int lev,map<int,vector<int>> &mp)
{
    if(!root)return;
    mp[lev].push_back(root->data);
    dfs(root->left,lev+1,mp);
    dfs(root->right,lev,mp);
}


class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        if(!root) return{};
        map<int,vector<int>> mp;
        // queue<pair<Node*,int>> q; //node and level
        // q.push({root,0});
        // while(!q.empty())
        // {
        //     auto p=q.front();
        //     q.pop();
        //     int lev=p.second;
        //     Node* nd=p.first;
        //     mp[lev].push_back(nd->data);
        //     if(nd->left)
        //      q.push({nd->left,lev+1}); //+1 as it now creates a new diagonal
        //     if(nd->right)
        //      q.push({nd->right,lev}); //same as parent
        // }
        
        vector<int> res;
        dfs(root,0,mp);
        for(auto p:mp)
        {
            res.insert(res.end(),p.second.begin(),p.second.end());
        }
        return res;
    }
};
/*Node class of the binary tree:
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        vector<int> res;
        map<int,int> mp; //no. and the sum;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int lev=p.second;
            Node* nd=p.first;
            mp[lev]+=nd->data;
            if(nd->left!=NULL)
             q.push({nd->left,lev-1});
            if(nd->right!=NULL)
             q.push({nd->right,lev+1});
        }
        for(auto p:mp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};
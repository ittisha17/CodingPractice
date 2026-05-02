/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

*/

bool find_ancestors(Node*root,vector<int>&temp,int target)
{
    if(root==NULL) return false;
    if(root->data==target)
     return true;
    temp.push_back(root->data);
    //if found in left
    if(find_ancestors(root->left,temp,target))
     return true;
     
    if(find_ancestors(root->right,temp,target))
     return true;
    
    temp.pop_back();
    return false;
    
    
}

class Solution {
  public:
    vector<int> ancestors(Node *root, int target) {
        // Code here
        vector<int> temp;
        find_ancestors(root,temp,target);
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
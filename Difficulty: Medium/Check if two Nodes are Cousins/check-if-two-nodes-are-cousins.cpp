/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
vector<long long> depth(int parent,Node*root,int x,int d)
{   
    if(root==NULL)
     return {-1,-1};
    if(root->data==x)
     return {d,parent};
     
    auto left=depth(root->data,root->left,x,d+1);
     if(left[0]!=-1)
      return left;
     auto right=depth(root->data,root->right,x,d+1);
     return right;
    
}

class Solution {
  public:
    // Function to check if two nodes are cousins in a tree
    bool isCousins(Node* root, int x, int y) {
        // write code here
        
        auto v1=depth(-1,root,x,0);
        int d1=v1[0];
        int parent1=v1[1];
        auto v2=depth(-1,root,y,0);
        int d2=v2[0];
        int parent2=v2[1];
        if(d1==d2 && parent1!=parent2)
          return true;
        return false;
    }
};
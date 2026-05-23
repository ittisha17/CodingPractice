/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

int Sum(Node*root)
{
    if(root==NULL) return 0;
    int sum;
    int val=root->data;
    if(root->left==NULL && root->right==NULL)
     {
         sum=0;
         root->data=0;
     }
    else
   {   sum=Sum(root->left)+Sum(root->right);
       root->data=sum;
   }
   return sum+val;
}

class Solution {
  public:
    void toSumTree(Node *root) {
        // code here
        Sum(root);
    }
};
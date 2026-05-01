/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void Calc(Node*root,int k,unordered_map<int,int>&mp,int &cnt,int sum)
{
    if(root==NULL)
     return ;
    sum+=root->data;
    if(sum==k)
     cnt++;
    if(mp.find(sum-k)!=mp.end())
         cnt+=mp[sum-k];
    
    mp[sum]++;
    Calc(root->left,k,mp,cnt,sum);
    Calc(root->right,k,mp,cnt,sum);
    mp[sum]--;
}

class Solution {
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int,int>mp;
        int cnt=0;
        int sum=0;
        Calc(root,k,mp,cnt,sum);
        return cnt;
        
        
        
    }
};
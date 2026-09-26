/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    void preorder(TreeNode*root,string &curr)
    {
        if(!root)
        {
            curr+="N,";
            return ;
        }
        
        curr+=to_string(root->val)+',';
        preorder(root->left,curr);
        preorder(root->right,curr);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorder(root,s);
        return s;
    }

    TreeNode*des(vector<string>&vec,int&id,int n) //give subtree rooted at id
    {
       if(id==n) return NULL;
        if(vec[id]=="N") 
        { id++;
          return NULL;
        }
        TreeNode*node=new TreeNode(stoi(vec[id]));
        id++;
        node->left=des(vec,id,n);
        node->right=des(vec,id,n);
        return node;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec;
        int i=0;
        int n=data.length();
        while(i<n)
        {
            if(data[i]=='N')
            {   vec.push_back("N");
                i+=2;
            }
            else 
            {  string num="";
                while(data[i]!=',')
                {
                    num+=data[i];
                    i++;
                }
                vec.push_back(num);
                i++;
            }
        }
        n=vec.size();
        int id=0;
        return des(vec,id,n);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
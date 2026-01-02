void eval(vector<int> &temp,int id,int k,int n,vector<vector<int>> &res)
{
    if(temp.size()==k)
    {
        res.push_back(temp);
        return;
    }
    if(id>n || temp.size()>k) return;
    temp.push_back(id);
    eval(temp,id+1,k,n,res);
    temp.pop_back();
    eval(temp,id+1,k,n,res);
    return;
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        int id=1;
        eval(temp,id,k,n,res);
        return res;
    }
};
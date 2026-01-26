
void solve(vector<int>&temp,vector<vector<int>>&res,vector<int>&arr,vector<bool>&incl)
{
    if(temp.size()==arr.size())
    {
        res.push_back(temp);
        return;
    }

    for(int i=0;i<arr.size();i++)
    {
      if(!incl[i])
      { incl[i]=true;
        temp.push_back(arr[i]);
        solve(temp,res,arr,incl);
        incl[i]=false;
        temp.pop_back();
       }
    }
  
}

class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> res;
        vector<int> temp;
         vector<bool>incl(n,false);
                solve(temp,res,arr,incl);
             
        return res;
        
    }
};
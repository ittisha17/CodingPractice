
void Solve(int i,int curr_sum,int k,int sum,vector<int>&temp,vector<vector<int>>&res)
{  
  
   if(curr_sum==sum && temp.size()==k)
    {
        res.push_back(temp);
        return;
    }
     if(i>=10 ||curr_sum>sum || temp.size()>k)
    return;

  temp.push_back(i);
  Solve(i+1,curr_sum+i,k,sum,temp,res);
  temp.pop_back();
  Solve(i+1,curr_sum,k,sum,temp,res);

}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum=n;
        vector<int>temp;
        vector<vector<int>> res;
        int curr_sum=0;
        Solve(1,curr_sum,k,sum,temp,res);
        return res;

    }
};
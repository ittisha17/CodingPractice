void solve(vector<int>&temp,vector<int>&nums,vector<vector<int>>&res,vector<bool>&vis)
{
    if(temp.size()==nums.size())
    { res.push_back(temp);
     return;}
  for(int j=0;j<nums.size();j++)
  {
    if(vis[j]) continue;
    if(j>0 && nums[j]==nums[j-1] && !vis[j-1])
     continue;
    
    vis[j]=true;
    temp.push_back(nums[j]);
    solve(temp,nums,res,vis);
    temp.pop_back();
    vis[j]=false;
  }
  return;
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n=nums.size();
        int id=0;
        sort(nums.begin(),nums.end());
        vector<bool> vis(n,false);
        solve(temp,nums,res,vis);
        return res;
    }
};